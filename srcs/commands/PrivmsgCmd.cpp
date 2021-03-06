#include "PrivmsgCmd.hpp"


// MARK: - Class Constructor

PrivmsgCmd::PrivmsgCmd(std::vector<std::string> &args, User *user) : Command(PRIVMSG, args, user) {}


// MARK: - Class Distructor

PrivmsgCmd::~PrivmsgCmd(void) {}


// MARK: - Class Methods

void	PrivmsgCmd::execute(void) {
	if (user->getState() != User::ACTIVE)
		return ;

	if (args.size() != 4)
		return ;
	
	std::string target = args.at(1);
	std::string msg = args.at(2);

	if (msg[0] == ':')
		msg.erase(0, 1);

	if (target.at(0) == '#') {
		
		Channel *channel = channelsList->getChannel(target);
		if (channel) {
			if (channel->isMember(user->getNickname()))
				channel->mailing(":" + user->getNickname() + " PRIVMSG " + target + " :" + msg, user);
			else
				user->appendMessage(":server " + std::string(ERR_USERNOTINCHANNEL)
				+ " " + user->getNickname() + ": You're not member of this channel");
		} else {
			user->appendMessage(":server " + std::string(ERR_NOSUCHCHANNEL) + " " + user->getNickname()
				+ " : No such channel");
		}

	} else {
		User *targetUser = usersList->getUser(target);
		if (targetUser) {
			targetUser->appendMessage(":" + user->getNickname() + "!" + user->getNickname()
			+ "@" + user->getAddress() + " PRIVMSG " + target + " :" + msg);
		} else {
			user->appendMessage(":server " + std::string(ERR_NOSUCHNICK) + " " + user->getNickname()
				+ " : No such nick/channel");
		}
	}
}
