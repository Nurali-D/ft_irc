#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "../commands/Command.hpp"
#include <stack>
#include "../headers/libraryHeaders.hpp"
#include "User.hpp"
#include "Channel.hpp"
// #include "../commands/Nick.hpp"
// #include "../commands/Pass.hpp"
// #include "../commands/Privmsg.hpp"
// #include "../commands/UserCmd.hpp"
class Message
{
	
	private:
		User					*fromUser;
		std::string				msgToParse;
		std::vector<User*>		usersList;
		std::vector<Channel*>	channelsList;
		void					findCommand(std::vector<std::string> &cmdWithArgs);
		std::string				stringToLower(std::string &str);
		std::string				password;

	public:
		Message(User *fromUser, std::string msgToParse, 
			std::vector<User*> usersList, std::vector<Channel*> channelsList,
			std::string password);
		~Message();

		void	parseMessage();
};

#endif
