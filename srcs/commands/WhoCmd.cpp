#include "WhoCmd.hpp"


// MARK: - Class Constructor

WhoCmd::WhoCmd(std::vector<std::string> &args, User *user) : Command(WHO, args, user) {}


// MARK: - Class Destructor

WhoCmd::~WhoCmd(void) {}


// MARK: - Class Methods

void	WhoCmd::execute(void) {

	if (args.size() == 2) {
		std::vector<User*> users = usersList->getUsers();
		std::stringstream ss;
		ss << users.size();
		std::string usersCount = ss.str();

		user->appendMessage(":server " + std::string(RPL_ENDOFWHO) + " : End of WHO");

		std::vector<User*>::iterator it;
		for (it = users.begin(); it != users.end(); ++it)
			user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " " + (*it)->getNickname() + " " + (*it)->getUsername() + "@" + (*it)->getAddress());

		if (users.size() == 1)
			user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " Server has : " + usersCount + " user.");
		else if (users.size() > 1)
			user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " Server has : " + usersCount + " users.");
		
		
		
	} else {
		Channel *channel = channelsList->getChannel(args.at(1));
		if (!channel)
			user->appendMessage(":server " + std::string(ERR_NOSUCHCHANNEL) + " " + args.at(1) + ": No such channel!");
		else {
			std::vector<User*> users = channel->getUsers();
			user->appendMessage(":server " + std::string(RPL_ENDOFWHO) + " : End of WHO");

			std::vector<User*>::iterator it;
			std::string channelAdmin = channel->getChannelOperator()->getNickname();
			for (it = users.begin(); it != users.end(); ++it) {
				std::string prefix;
				if ((*it)->getNickname() == channelAdmin)
					prefix += "@";
				user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " " + prefix + (*it)->getNickname() + " " + (*it)->getUsername() + "@" + (*it)->getAddress());
			}

			std::stringstream ss;
			ss << users.size();
			std::string usersCount = ss.str();
			if (users.size() == 1)
				user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " Channel " + channel->getName() + " has : " + usersCount + " user.");
			else if (users.size() > 1)
				user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " Channel " + channel->getName() + " has : " + usersCount + " users.");
			
		}
	}
}
