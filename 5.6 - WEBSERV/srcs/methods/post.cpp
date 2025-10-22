#include "server.hpp"

/* Dispatch to the matching function based on content-type or target path */

void	c_response::handle_post_request(const c_request &request, c_location *location)
{
	string	content_type = request.get_header_value("Content-Type");
	string	target = request.get_target();

	if (request.get_error() || request.get_status_code() != 200)
	{
		build_error_response(request.get_status_code(), request);
		return ;
	}

	if (location)
	{
		if (target == "/test_post")
			handle_test_form(request);
		else if (content_type.find("application/x-www-form-urlencoded") != string::npos)
			handle_contact_form(request, location);
		else if (target == "/page_upload.html" && content_type.find("multipart/form-data") != string::npos)
			handle_upload_form_file(request, location);
		else if (target == "/post_todo")
			handle_todo_form(request, location);
		else 
			build_error_response(404, request);
	}
}


void	c_response::handle_generic_post(const c_request &request)
{
	vector<char> body = request.get_body();
	string body_str(body.begin(), body.end());

	string escaped_body = escape_html(body_str);

	string html = "<!DOCTTYPE html>\n";
	html += "<html><head><title>POST Data Received</title></head>\n";
	html += "<body>\n";
    html += "<h1>POST Request Received</h1>\n";
	html += "<p><strong>Content-Type:</strong> " + request.get_header_value("Content-Type") + "</p>\n";
    html += "<p><strong>Content-Length:</strong> " + int_to_string(body.size()) + " bytes</p>\n";
    html += "<h2>Body:</h2>\n";
    html += "<pre>" + escaped_body + "</pre>\n";
    html += "<a href=\"/\">Back to home</a>\n";
    html += "</body></html>";

	_client.set_status_code (200);

	_file_content = html;
	build_success_response("response.html", request);
}


/* Process file uploads, validate size and content, saves files and redirect */

void	c_response::handle_upload_form_file(const c_request &request, c_location *location)
{
	size_t max_size = location->get_body_size();
    if (request.get_content_length() > max_size)
    {
        build_error_response(413, request);
        return;
    }
	vector<char> body = request.get_body();
	if (body.empty())
	{
		_server.log_message("[ERROR] Empty body for upload request");
		build_error_response(400, request);
		return ;
	}
	string content_type = request.get_header_value("Content-Type");
	string boundary = extract_boundary(content_type);
	if (boundary.empty() || get_status() >= 400)
	{
		build_error_response(get_status() >= 400 ? get_status() : 400, request);
		return ;
	}

	vector<s_multipart> parts = parse_multipart_data(body, boundary);
	if (get_status() >= 400)
	{
		build_error_response(get_status(), request);
		return ;
	}
	vector<string>	uploaded_files;
	for(size_t i = 0; i < parts.size(); i++)
	{
		s_multipart &part = parts[i];
		if (part.is_file)
		{
			string saved_path = save_uploaded_file(part, location);
			if (get_status() >= 400)
			{
				build_error_response(get_status(), request);
				return;
			}
			if (saved_path.empty())
			{
				build_error_response(500, request);
				return ;
			}
			uploaded_files.push_back(saved_path);
			_file_content = load_file_content(saved_path);
			_server.log_message("[INFO] ✅ UPLOADED FILE : " + part.filename 
									+ " (" + int_to_string(part.content.size()) + " bytes)");
		}
	}
	if (uploaded_files.size() > 0)
	{
		_response = "HTTP/1.1 303 See Other\r\n";
		_response += "Location: /page_upload.html\r\n";
		_response += "Content-Length: 0\r\n";
		_response += "Connection: keep-alive\r\n";
		_response += "Server: webserv/1.0\r\n\r\n";

		_server.log_message("[INFO] ✅ Upload done. Redirection to /page_upload.html");
		_client.set_last_modified();
	}
	else
		build_error_response(400, request);
}

/* Generate a unique filename if a file has the same name as a targfet directory*/

string	get_unique_filename(const string &directory, string &filename)
{
	string full_path = directory + filename;
	if (!file_exists(full_path))
		return filename;
	
	size_t dot_pos = filename.find_last_of('.');
	string name = filename.substr(0, dot_pos);
	string extension = filename.substr(dot_pos);

	int counter = 1;
	string new_filename;

	while (true)
	{
		ostringstream oss;
		oss << counter;
		new_filename = name + "_" + oss.str() + extension;
		full_path = directory + new_filename;

		if (!file_exists(full_path))
			return new_filename;
		counter++;
		if (counter > 1000)
		{
			ostringstream oss_t;
			oss_t << time(0);
			return name + "_" + oss_t.str() + extension;
		}
	}
}

/* Save uploaded file to the directory */

string	c_response::save_uploaded_file(const s_multipart &part, c_location *location)
{
	string upload_directory;

	if (location && location->get_upload_path().empty())
	{
		_server.log_message("[ERROR] No upload path defined.");
		_status = 500;
		return "";
	}
	upload_directory = location->get_upload_path();
	if (!directory_exists(upload_directory))
	{
		_server.log_message("[ERROR] Directory doesn't exist. Upload failed.");
		_status = 500;
		return "";
	}

	string safe_filename = sanitize_filename(part.filename, location);
	if (safe_filename.empty())
		return "";
	
	string final_path = upload_directory + safe_filename;
	if (file_exists(final_path))
	{
		safe_filename = get_unique_filename(upload_directory, safe_filename);
		final_path = upload_directory + safe_filename;
	}

	ofstream file(final_path.c_str(), ios::binary);
	if (!file.is_open())
	{
		_server.log_message("[ERROR] the server cannot upload file " + final_path);
		return "";
	}
	file.write(part.content.data(), part.content.size());
	file.close();
	return final_path;
}

string	c_response::extract_boundary(const string &content_type)
{
	string boundary;

	size_t pos = content_type.find("boundary=");
	if (pos != string::npos)
		boundary = content_type.substr(pos + 9);
	else
	{
		set_status(400);
		return "";
	}
	return boundary;
}

/* parse multipart body in single parts */

vector<s_multipart> const	c_response::parse_multipart_data(vector<char>& body, const string &boundary)
{
	string			delimiter = "--" + boundary;
	string			closing_delimiter = delimiter + "--";
	size_t			pos = 0;
	vector<size_t>	boundary_pos;

	while (pos < body.size())
	{
		vector<char>::iterator found = search(body.begin() + pos, body.end(), 
											delimiter.begin(), delimiter.end());
		if (found == body.end())
			break ;

		size_t found_pos = static_cast<size_t>(found - body.begin());
		boundary_pos.push_back(found_pos);
		pos = found_pos + delimiter.size();
	}

	if (boundary_pos.size() < 2)
		return (vector<s_multipart>());

	vector<s_multipart>	parts;
	for (size_t i = 0; i < boundary_pos.size() - 1; i++)
	{
		if (get_status() >= 400)
		{
			break;
		}
		size_t	begin = boundary_pos[i] + delimiter.length();
		if (begin < body.size() && body[begin] == '\r')
			begin++;
		if (begin < body.size() && body[begin] == '\n')
			begin++;

		size_t	end = boundary_pos[i + 1];
		if (end >= 2 && body[end - 2] == '\r' && body[end - 1] == '\n')
			end -= 2;
		else if (end >= 1 && body[end - 1] == '\n')
			end -= 1;
		
		if (begin >= end)
			continue;

		string	raw_part(body.begin() + begin, body.begin() + end);

		if (raw_part.find(closing_delimiter) != string::npos)
			continue;
		if (raw_part.find_first_not_of(" \r\n") == string::npos)
			continue;

		s_multipart single_part = parse_single_part(raw_part);

		if (get_status() >= 400)
		{
			break;
		}
		parts.push_back(single_part);
	}
	return parts;
}

/* parse one multipart section, extract headers and content */

s_multipart const	c_response::parse_single_part(const string &raw_part)
{

	s_multipart	part;

	if (get_status() >= 400)
	{
		return part;
	}
	size_t		separator_pos = raw_part.find("\r\n\r\n");
	if (separator_pos == string::npos)
	{
		set_status(400);
		return part;
	}

	string header_section = raw_part.substr(0, separator_pos);
	string content_section = raw_part.substr(separator_pos + 4);

	while (!content_section.empty() && (content_section[content_section.size() -1] == '\r'))
		content_section.erase(content_section.size() - 1, 1);
	while (!content_section.empty() && (content_section[content_section.size() -1] == '\n'))
		content_section.erase(content_section.size() - 1, 1);

	size_t pos = content_section.rfind("\r\n--");
	if ( pos != string::npos)
	{
		content_section.erase(pos);
	}

	parse_header_section(header_section, part);

	if (get_status() >= 400)
	{
		return part;
	}
	part.content = content_section;
	part.is_file = !part.filename.empty();

	return part;
}

/* parse header lines inside a multipart section, extract filename and content-type */

void	c_response::parse_header_section(const string &header_section, s_multipart &part)
{
	if (get_status() >= 400)
		return;

	size_t	pos_disposition = header_section.find("Content-Disposition");
	if (pos_disposition != string::npos)
	{
		string line = extract_line(header_section, pos_disposition);
		if (line.empty())
		{
			set_status(400);
			return;
		}
		part.name = extract_quotes(line, "name=");
		if (part.name.empty())
		{
			set_status(400);
			return;
		}
		part.filename = extract_quotes(line, "filename=");
	}
	else
	{
		set_status(400);
		return;
	}

	size_t	pos_type = header_section.find("Content-Type");
	if (pos_type != string::npos)
	{
		string line = extract_line(header_section, pos_type);
		part.content_type = extract_after_points(line);
		if (part.content_type.empty())
		{
			set_status(400);
		}
	}
}

/* extracts a single header line fr om a given position */

string	c_response::extract_line(const string &header_section, const size_t &pos)
{
	size_t	end_pos = header_section.find("\r\n", pos);

	if (end_pos == string::npos)
		end_pos = header_section.length();
	
	string line = header_section.substr(pos, end_pos - pos);
	return line;
}

/* extract a "quoted" value */

string	c_response::extract_quotes(const string &line, const string &type)
{
	size_t key_pos = line.find(type);
	if (key_pos == string::npos)
		return "";
	
	size_t first_quote = line.find('"', key_pos);
	if (first_quote == string::npos)
		return "";
	size_t second_quote = line.find('"', first_quote + 1);

	if (second_quote == string::npos)
		return "";
	
	string value = line.substr(first_quote + 1, second_quote - first_quote - 1);
	return trim(value);
}

string	c_response::extract_after_points(const string &line)
{
	size_t pos = line.find(':');
	if (pos == string::npos)
		return "";
	
	string value = line.substr(pos + 1);
	return trim(value);
}

/*******************   contact form    *******************/

void	c_response::handle_contact_form(const c_request &request, c_location *location)
{
	vector<char> body = request.get_body();
	map<string, string> form_data = parse_form_data(body);

	if (form_data["nom"].empty() || form_data["email"].empty())
	{
		build_error_response(400, request);
		return;
	}

	if (save_contact_data(form_data, location))
	{
		_response = "HTTP/1.1 303 See Other\r\n";
		_response += "Location: /contact_success.html\r\n";
		_response += "Content-Length: 0\r\n";
		_response += "\r\n";
		return;
	}
	else
		build_error_response(500, request);
}

bool	c_response::save_contact_data(const map<string, string> &data, c_location *location)
{	
	string path;

	if (location && location->get_upload_path().empty())
	{
		_status = 500;
		_server.log_message("[ERROR] There is no upload path defined for upload the data. ");
		return false;
	}
	if (location && !location->get_upload_path().empty())
	{
		path = location->get_upload_path();
		if (!directory_exists(path))
		{
			_status = 500;
			_server.log_message("[ERROR] The upload path defined is not existing, the data can't be download. ");
			return false;
		}

	}
	
	string filename = path + "contact.txt"; 

	ofstream file(filename.c_str(), ios::binary | ios::app);
	if (!file.is_open())
	{
		_server.log_message("[ERROR] The file can't be created " + filename);
		_status = 500;
		return false;
	}

	time_t now = time(0);
	char *str_time = ctime(&now);
	str_time[strlen(str_time) - 1] = '\0';

	file << "[ " << str_time << " ] ";
	for (map<string, string>::const_iterator it = data.begin(); it != data.end(); it++)
	{
		file << it->first << "=" << it->second << "; ";
	}
	file << endl;
	file.close();
	
	return true;
}

string  c_response::extract_extension(const string &filename, string &name, c_location *location)
{
	size_t point_pos = filename.find_last_of(".");
	if (point_pos == string::npos)
		return "";
	if (point_pos == 0)
		return "";
	string extension = filename.substr(point_pos);
	name = filename.substr(0, point_pos);

	if (location->get_allowed_extensions().empty() || 
		find(location->get_allowed_extensions().begin(), location->get_allowed_extensions().end(), extension) != location->get_allowed_extensions().end())
	{
		return extension;
	}
	else 
	{
		cout << "Error: extension not allowed (" << extension << ")" << endl;
		return "";
	}
	return extension;
}


string  c_response::sanitize_filename(const string &filename, c_location *location)
{
	string name;
	string extension = extract_extension(filename, name, location);
	if (extension.empty())
	{
		set_status(415);
		return "";
	}
	if (name.empty())
		name = "file";

	string clean_name;
	for(size_t i = 0; i < name.size(); i++)
	{
		char c = name[i];
		if (isalnum(static_cast<unsigned char>(c)))
			clean_name += c;
		else if (c == '_' || c == '-' || c == ' ')
			clean_name += '_';
		else
			clean_name += '_';
	}
	while (clean_name.find("__") != string::npos)
		clean_name.replace(clean_name.find("__"), 2, "_");
	while (!clean_name.empty() && clean_name[clean_name.size() - 1] == '_')
		clean_name.erase(clean_name.size() - 1);
	if (clean_name.size() > 200)
		clean_name = clean_name.substr(0, 200);
	clean_name = trim_underscore(clean_name);
	if (!extension.empty())
		return clean_name += extension;
	else
		return clean_name;
}

/********************    test form    ********************/

void	c_response::handle_test_form(const c_request &request)
{
	map<string, string> form_data = parse_form_data(request.get_body());
	create_form_response(form_data, request);
}

void	c_response::create_form_response(const map<string, string> &form, const c_request &request)
{
	string html = "<!DOCTYPE html>\n<html><head><title>Formulaire recu</title></head>\n<body>\n";
	html += "<h1>Donnees recues :</h1>\n<ul>\n";

	for (map<string, string>::const_iterator it = form.begin(); it != form.end(); it++)
	{
		html += "<li><strong>" + it->first + "</strong>" + ": " + it->second + "</li>\n";
	}
	html += "</ul>\n<a href=\"/post_test.html\">Nouveau formulaire</a>\n</body></html>";
	_file_content = html;
	build_success_response("response.html", request);
}

string const	c_response::url_decode(const string &body)
{
	string	res;
	size_t	i = 0;
	
	while (i < body.size())
	{
		if (body[i] == '+')
		{
			res += ' ';
			i++;
		}
		else if (body[i] == '%' && i + 2 < body.size())
		{
			bool	is_hexa = true;
			string hex_str = body.substr(i + 1, 2);
			for (size_t j = 0; j < hex_str.size(); ++j)
			{
				if (!isxdigit(hex_str[j]))
					is_hexa = false;
			}
			if (is_hexa)
			{
				int value = 0;
				istringstream iss(hex_str);
				iss >> std::hex >> value;
				res += static_cast<char>(value);
				i +=3 ;
			}
			else
			{
				res += body[i];
				i++;
			}
		}
		else
		{
			res += body[i];
			i++;
		}
	}
	return res;
}

map<string, string> const	c_response::parse_form_data(const vector<char>& body)
{
	map<string, string>	form_data;

	if (body.empty())
		return (form_data);

	size_t start = 0;

	while (start < body.size())
	{
		size_t	pos_and = start;
		while (pos_and < body.size() && body[pos_and] != '&')
			pos_and++;

		size_t pos_equal = start;
		while (pos_equal < pos_and && body[pos_equal] != '=')
			pos_equal++;

		string	key;
		string	value;
		
		if (pos_equal > start)
			key.assign(&body[start], &body[pos_equal]);
		if (pos_equal < pos_and)
			value.assign(&body[pos_equal + 1], &body[pos_and]);

		key = url_decode(key);
		value = url_decode(value);

		form_data[key] = value;

		start = pos_and + 1;
	}
	return form_data;
}

/***** TODO ******/

void c_response::handle_todo_form(const c_request &request, const c_location *location)
{
	map<string, string>form = parse_form_data(request.get_body());
	string task;

	map<string, string>::iterator it = form.find("task");
	if (it != form.end())
		task = it->second;
	else
		task = "";
	if (task.empty())
	{
		build_error_response(400, request);
		return ;
	}

	string path;

	if (location && location->get_upload_path().empty())
	{
		_status = 500;
		_server.log_message("[ERROR] There is no upload path defined for upload the data. ");
		return;
	}
	if (location && !location->get_upload_path().empty())
	{
		path = location->get_upload_path();
		if (!directory_exists(path))
		{
			_status = 500;
			_server.log_message("[ERROR] The upload path defined is not existing, the data can't be download. ");
			return;
		}

	}
	
	string filename = path + "todo.txt"; 

	ofstream file(filename.c_str(), ios::app);
	if (!file.is_open())
	{
		build_error_response(500, request);
		return ;
	}
	file << task << endl;
	file.close();
	load_todo_page(request);
}

/* Load the upload page, list all the files already uploaded */

void	c_response::load_upload_page(const c_request &request)
{
	c_location *location = _server.find_matching_location("/page_upload");
	if (!location || location->get_upload_path().empty())
	{
		_server.log_message("[ERROR] Cannot load upload page, no path configured");
		build_error_response(500, request);
		return ;
	}

	string upload_directory = location->get_upload_path();
	string page_upload_directory;

	if (location->get_alias().empty())
	{
		if (_server.get_root().empty() || !is_directory(_server.get_root()))
		{
			_server.log_message("[ERROR] Cannot load page_upload.html, no path configured or existing");
			build_error_response(500, request);
			return ;
		}
		else
			page_upload_directory = _server.get_root();
	}
	else if (!is_directory(location->get_alias()))
	{
		_server.log_message("[ERROR] Cannot load page_upload.html, no path configured or existing");
		build_error_response(500, request);
		return ;
	}
		
	else
		page_upload_directory = location->get_alias();

	string html_template = load_file_content(page_upload_directory + "/page_upload.html");
	string files_html;

	size_t max_body_size = request.get_client_max_body_size();
	string max_body_size_str = int_to_string(max_body_size);

	DIR *dir = opendir(upload_directory.c_str());
	if (dir)
	{
		struct dirent *entry;
		while ((entry = readdir(dir)) != NULL)
		{
			string filename = entry->d_name;
			if (filename == "." || filename == "..")
				continue;

			files_html += "<div class=\"file-item\">";
			files_html += "<div class=\"file-info\">";
			files_html += "<span class=\"file-name-list\">" + filename + "</span>";
			files_html += "</div>";
			files_html += "<button class=\"delete-btn\" onclick=\"deleteFile('" + filename + "')\">DELETE</button>";
			files_html += "</div>\n";
		}
		closedir(dir);
	}
	else
	{
		files_html = "<div class=\"empty-message\">No uploaded files yet.</div>";
	}

	size_t pos = html_template.find("{{MAX_BODY_SIZE}}");
	if (pos != string::npos)
		html_template.replace(pos, strlen("{{MAX_BODY_SIZE}}"), max_body_size_str);

	pos = html_template.find("{{FILES_HTML}}");
	if (pos != string::npos)
		html_template.replace(pos, strlen("{{FILES_HTML}}"), files_html);

	_file_content = html_template;
	build_success_response("page_upload.html", request);
}