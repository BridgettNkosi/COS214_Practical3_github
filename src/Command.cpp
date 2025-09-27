/**
 * @file Command.cpp
 * @brief Implementation of Command and concrete command classes.
 */

#include "Command.h"
#include "ChatRoom.h"
#include "User.h"
#include <iostream>
using namespace std;

Command::Command(ChatRoom* room, User* from, const string &message)
    : room_(room), fromUser_(from), message_(message) {}

Command::~Command() {}

SendMessageCommand::SendMessageCommand(ChatRoom* room, User* from, const string &message)
    : Command(room, from, message) {}

SendMessageCommand::~SendMessageCommand() {}

void SendMessageCommand::execute() {
    if (!room_ || !fromUser_) return;
    room_->sendMessage(message_, fromUser_);
}

SaveMessageCommand::SaveMessageCommand(ChatRoom* room, User* from, const string &message)
    : Command(room, from, message) {}

SaveMessageCommand::~SaveMessageCommand() {}

void SaveMessageCommand::execute() {
    if (!room_ || !fromUser_) return;
    room_->saveMessage(message_, fromUser_);
}
