#include "server.hpp"

/* Handles delete request by checking permissions, and removing specific files if allowed */

void	c_response::handle_delete_request(const c_request &request, string file_path)
{
	if (file_path.find("..") != string::npos)
	{
		build_error_response(403, request);
		return ;
	}
	if (!is_existing_file(file_path))
	{
		build_error_response(404, request);
		return ;
	}

	struct stat file_stat;
	string dir = file_path.substr(0, file_path.find_last_of('/'));
	if (stat(file_path.c_str(), &file_stat) == 0 && S_ISDIR(file_stat.st_mode))
	{
		build_error_response(403, request);
		return ;
	}
	if (access(dir.c_str(), W_OK) != 0)
	{
		build_error_response(409, request);
		return ;
	}
	if (access(file_path.c_str(), W_OK) != 0)
	{
		build_error_response(403, request);
		return ;
	}
	if (remove(file_path.c_str()) != 0)
	{
		build_error_response(500, request);
		return ;
	}
}

/* Loads the page, insert all the taks and build success response */

void	c_response::load_todo_page(const c_request &request)
{
	c_location *location = _server.find_matching_location("/post_todo");
	if (!location || location->get_upload_path().empty())
	{
		_server.log_message("[ERROR] Cannot load todo task, no path configured for the download.");
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

	string filename = upload_directory + "todo.txt";
	string todo_html = load_file_content(page_upload_directory + "todo.html");
	ifstream infile(filename.c_str());
	string tasks_html;
	string line;

	while (getline(infile, line))
	{
		string safe_line_html = escape_html(line);
		string attr_value      = escape_html_attr(line);

		tasks_html += "<div class=\"todo-item\">";
		tasks_html += "<span class=\"task-text\">" + safe_line_html + "</span>";
		tasks_html += "<button class=\"delete-btn\" data-task=\"" + attr_value
					+ "\" onclick=\"deleteTask(this.dataset.task)\">DELETE</button>";
		tasks_html += "</div>\n";
	}
	infile.close();

	size_t pos = todo_html.find("{{TASKS_HTML}}");
	if (pos != string::npos)
		todo_html.replace(pos, strlen("{{TASKS_HTML}}"), tasks_html);
	_file_content = todo_html;
	build_success_response("todo.html", request);
}

/* Delete a specific task from the todo list and reload the updated page */

void c_response::handle_delete_todo(const c_request &request)
{
	c_location *location = _server.find_matching_location("/post_todo");
	if (!location || location->get_upload_path().empty())
	{
		_server.log_message("[ERROR] Cannot load todo task, no path configured for the download.");
		build_error_response(500, request);
		return ;
	}

	string upload_directory = location->get_upload_path();
	string target = request.get_target();
	string task_to_delete;
	size_t pos = target.find("?task=");
	if (pos != string::npos)
	{
		task_to_delete = target.substr(pos + 6);
		task_to_delete = url_decode(task_to_delete);
	}
	else
	{
		build_error_response(400, request);
		return ;
	}

	string filename = upload_directory + "todo.txt";
	ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		build_error_response(500, request);
		return ;
	}
	
	vector<string> tasks;
	string line;
	int line_count = 0;
	bool found = false;

	while (getline(infile, line))
	{
		line_count++;
		if (line == task_to_delete)
			found = true;
		else
			tasks.push_back(line);
	}
	infile.close();
	if (!found)
		_server.log_message("[ERROR] Task cannot be found");
	
	ofstream outfile(filename.c_str(), ios::trunc);
	if (!outfile.is_open())
	{
		build_error_response(500, request);
		return ;
	}

	for (size_t i = 0; i < tasks.size(); i++)
		outfile << tasks[i] << endl;
	outfile.close();
	load_todo_page(request);
}

/* Handle file delete request after checking filename and access permissions */

void c_response::handle_delete_upload(const c_request &request)
{
	string target = request.get_target();
	string file_to_delete;
	size_t pos = target.find("?file=");
	
	if (pos != string::npos)
	{
		file_to_delete = target.substr(pos + 6);
		file_to_delete = url_decode(file_to_delete);
	}
	else
	{
		build_error_response(400, request);
		return ;
	}

	if (file_to_delete.find("..") != string::npos)
	{
		build_error_response(403, request);
		return ;
	}
	
	string path_location = target.substr(0, pos);
	c_location *location = _server.find_matching_location(path_location);
	string upload_directory;

	if (!location && location->get_upload_path().empty())
	{
		_server.log_message("[ERROR] No upload path found for target: " + target);
		build_error_response(500, request);
		return ;
	}
	upload_directory = location->get_upload_path();

	string filename = upload_directory + file_to_delete;

	if (access(upload_directory.c_str(), W_OK) != 0)
	{
		_server.log_message("[ERROR] No write access to directory: " + upload_directory);
		build_error_response(403, request);
		return ;
	}
	if (access(filename.c_str(), W_OK) != 0)
	{
		_server.log_message("[ERROR] No write access to filename: " + filename);
		build_error_response(403, request);
		return ;
	}
	if (remove(filename.c_str()) != 0)
	{
		_server.log_message("[ERROR] file not found or cannot be deleted: " + filename);
		build_error_response(404, request);
		return ;
	}
	
	_server.log_message("[INFO] ✅ FILE DELETED: " + filename);
	load_upload_page(request);
}
