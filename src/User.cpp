/**
 * @file User.cpp
 * @brief Implementation of User methods.
 */

#include "User.h"
#include "ChatRoom.h"
#include "Command.h"
#include <iostream>
using namespace std;

User::User(const string &name) : name_(name) {}

User::~User() {
    for (size_t i = 0; i < commandQueue_.size(); ++i) {
        delete commandQueue_[i];
    }
    commandQueue_.clear();
}

const string& User::getName() const { return name_; }

void User::joinRoom(ChatRoom* room) {
    if (!room) return;
    for (size_t i = 0; i < chatRooms_.size(); ++i) if (chatRooms_[i] == room) return;
    chatRooms_.push_back(room);
    room->registerUser(this);
}

void User::leaveRoom(ChatRoom* room) {
    for (size_t i = 0; i < chatRooms_.size(); ++i) {
        if (chatRooms_[i] == room) {
            chatRooms_.erase(chatRooms_.begin() + i);
            room->removeUser(this);
            return;
        }
    }
}

void User::send(const string &message, ChatRoom* room) {
    if (!room) return;
    Command* sendCmd = new SendMessageCommand(room, this, message);
    Command* saveCmd = new SaveMessageCommand(room, this, message);

    addCommand(sendCmd);
    addCommand(saveCmd);
    executeAll();
}

void User::receive(const string &message, User* fromUser, ChatRoom* room) {
    cout << "[" << room->getName() << "] " << fromUser->getName() << " -> " << name_
         << ": " << message << endl;
}

void User::addCommand(Command* cmd) {
    if (!cmd) return;
    commandQueue_.push_back(cmd);
}

void User::executeAll() {
    for (size_t i = 0; i < commandQueue_.size(); ++i) {
        Command* c = commandQueue_[i];
        if (c) c->execute();
        delete c;
    }
    commandQueue_.clear();
}
