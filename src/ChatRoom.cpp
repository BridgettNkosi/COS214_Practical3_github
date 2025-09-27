/**
 * @file ChatRoom.cpp
 * @brief Implementation of ChatRoom and concrete chat rooms.
 */

#include "ChatRoom.h"
#include "Memento.h"
#include "User.h"
using namespace std;

ChatRoom::ChatRoom(const string &name) : name_(name) {}

ChatRoom::~ChatRoom() {}

void ChatRoom::registerUser(User* user) {
    for (size_t i = 0; i < users_.size(); ++i) {
        if (users_[i] == user) return;
    }
    users_.push_back(user);
}

void ChatRoom::removeUser(User* user) {
    for (size_t i = 0; i < users_.size(); ++i) {
        if (users_[i] == user) {
            users_.erase(users_.begin() + i);
            return;
        }
    }
}

void ChatRoom::sendMessage(const string &message, User* fromUser) {
    for (size_t i = 0; i < users_.size(); ++i) {
        User* u = users_[i];
        if (u != fromUser) {
            u->receive(message, fromUser, this);
        }
    }
}

void ChatRoom::saveMessage(const string &message, User* fromUser) {
    string entry = fromUser ? (fromUser->getName() + ": " + message) : message;
    chatHistory_.push_back(entry);
}

const string& ChatRoom::getName() const { return name_; }

size_t ChatRoom::userCount() const { return users_.size(); }
User* ChatRoom::getUserAt(size_t idx) const { return users_.at(idx); }

size_t ChatRoom::historySize() const { return chatHistory_.size(); }
const string& ChatRoom::getHistoryAt(size_t idx) const { return chatHistory_.at(idx); }

Memento* ChatRoom::createMemento() const {
    return new Memento(chatHistory_);
}

void ChatRoom::restoreMemento(Memento* m) {
    if (!m) return;
    chatHistory_ = m->getState();
}

void ChatRoom::freeMemento(Memento* m) {
    delete m;
}

CtrlCat::CtrlCat() : ChatRoom("CtrlCat") {}
CtrlCat::~CtrlCat() {}

Dogorithm::Dogorithm() : ChatRoom("Dogorithm") {}
Dogorithm::~Dogorithm() {}
