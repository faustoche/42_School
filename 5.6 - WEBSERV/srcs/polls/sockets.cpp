#include "server.hpp"

/* Create and configure TCP socket for each port, with options,
bind the socket with the network adress and the port,
listen on the socket and set non blocking socket */

void c_server::create_socket_for_each_port(const std::vector<int>&ports)
{
	for (std::vector<int>::const_iterator it = ports.begin(); it != ports.end(); it++)
	{
		int port = *it;
		int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
		if (socket_fd < 0)
		{
			log_message("[ERROR] Socket's creation for port " + int_to_string(port) + " - " + int_to_string(errno));
			continue ;
		}
		int socket_option = 1;
		if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &socket_option, sizeof(socket_option)) < 0)
		{
			log_message("[ERROR] Socket's option for port " + int_to_string(port) + " - " + int_to_string(errno));
			close(socket_fd);
			continue ;
		}
		sockaddr_in socket_address;
		memset(&socket_address, 0, sizeof(socket_address));
		socket_address.sin_family = AF_INET;
		socket_address.sin_port = htons(port);
		socket_address.sin_addr.s_addr = INADDR_ANY;

		if (bind(socket_fd, (struct sockaddr*)&socket_address, sizeof(socket_address)) < 0)
		{
			log_message("[ERROR] Bind for port " + int_to_string(port) + " - " + int_to_string(errno));
			close (socket_fd);
			continue ;
		}
		if (listen(socket_fd, SOMAXCONN) < 0)
		{
			log_message("[ERROR] Listen for port " + int_to_string(port) + " - " + int_to_string(errno));
			close(socket_fd);
			continue ;
		}
		set_non_blocking(socket_fd);
		_multiple_ports[socket_fd] = port;
	}
}


/* Check if a fd correspond to a socket wich is listen and handle by the server */

bool c_server::is_listening_socket(int fd)
{
	return (_multiple_ports.find(fd) != _multiple_ports.end());
}


/* Return the port bind to a socket or -1 if the socket is unknown */

int c_server::get_port_from_socket(int socket_fd)
{
	std::map<int, int>::iterator it = _multiple_ports.find(socket_fd);
	if (it != _multiple_ports.end())
		return (it->second);
	return (-1);
}


/* Clean all sockets clients and servers, kill CGI, clean maps and struct */

void	c_server::close_all_sockets_and_fd(void)
{
	if (_clients.size() > 0)
	{
		cout << GREEN << endl << "🐕 Clients connexions closed (" << _clients.size() << ")" << RESET << endl;
		cout << GREEN << "🧦 Sockets closed!" << RESET << endl;
		for (map<int, c_client*>::iterator it = _clients.begin(); it != _clients.end(); it++)
		{
			int client_fd = it->first;
			close(client_fd);
			delete(it->second);
		}
		_clients.clear();
	}

	if (_active_cgi.size() > 0)
	{
		for (std::map<int, c_cgi*>::iterator it = _active_cgi.begin(); it != _active_cgi.end(); )
		{
		    std::map<int, c_cgi*>::iterator to_delete = it++;
		    if (to_delete->second)
			{
				pid_t pid = to_delete->second->get_pid();
    	        kill(pid, SIGTERM);
    	        waitpid(pid, NULL, 0);
		        delete to_delete->second;
			}
		    _active_cgi.erase(to_delete);
		}
		cout << GREEN << "🧬 Active CGI has been cleaned !" << RESET << endl;
	}

	if (_multiple_ports.size() > 0)
	{
		for (map<int, int>::iterator it = _multiple_ports.begin(); it != _multiple_ports.end(); it++)
		{
			int socket_fd = it->first;
			close(socket_fd);
		}
		_multiple_ports.clear();
	}
	
	_poll_fds.clear();
	cout << GREEN << "✅ SERVER CLOSED!" << RESET << endl;
}