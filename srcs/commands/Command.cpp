#include "Command.hpp"
#include <algorithm>
#include "PassCmd.hpp"
#include "NickCmd.hpp"
#include "UserCmd.hpp"
#include "PrivmsgCmd.hpp"
#include "JoinCmd.hpp"


// MARK: - Class Constructor


Command::Command(Command::CmdType cmd, std::vector<std::string> &args, User *user)
:
	cmd(cmd),
	args(args),
	user(user)
{}

const std::string Command::cmdsArray[] = {"pass", "nick", "user", "privmsg", "join"};
// note: индекс команд 
// в массиве cmdsArray должен совпадать c последовательностью в enum CmdType


// MARK: - Class Distructor

Command::~Command(void) {}


// MARK: - Class Methods

void Command::setUsersList(std::vector<User*> *usersList) {
	this->usersList = usersList;
}

void Command::setChannelsList(std::vector<Channel*> *channelsList) {
	this->channelsList = channelsList;
}

Command *Command::createCmd(std::string &cmdName, std::vector<std::string> &args, User *user) {
	int index;
	int arraySize = sizeof(cmdsArray) / sizeof(cmdsArray[0]);
	const std::string *cmdIter = std::find(cmdsArray, cmdsArray + arraySize, cmdName);

	index = (cmdIter != &cmdsArray[arraySize]) ? std::distance(cmdsArray, cmdIter) : -1;

	switch (index) {
		case PASS :
			return new PassCmd(args, user);
		case NICK :
			return new NickCmd(args, user);
		case USER :
			return new UserCmd(args, user);
		case PRIVMSG :
			return new PrivmsgCmd(args, user);
		case JOIN :
			return new JoinCmd(args, user);
		
		// note: добавлять сюда все остальные команды и в cmdsArray
	}
	return NULL;
}