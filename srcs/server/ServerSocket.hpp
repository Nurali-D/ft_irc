#include "../headers/libraryHeaders.hpp"

#ifndef SERVERSOCKET_HPP
# define SERVERSOCKET_HPP

class ServerSocket
{
public:
	ServerSocket();
	ServerSocket(const char &ip, int port, std::string password);
	~ServerSocket();
	ServerSocket(const ServerSocket &other);
	ServerSocket	&operator=(const ServerSocket &other);
	int				getSocketFd() const;
	void			setSocketForListen(const char &ip, int port);
	std::string		getPassword() const;
private:
	int					listenSocketFd;
	struct sockaddr_in	listenSocketAddr;
	std::string			password;
};

#endif