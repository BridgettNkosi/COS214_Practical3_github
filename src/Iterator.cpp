/**
 * @file Iterator.cpp
 * @brief Implementation of simple iterators.
 */

#include "Iterator.h"
#include "ChatRoom.h"
#include "User.h"
using namespace std;

UserIterator::UserIterator(const ChatRoom* room) : room_(room), idx_(0) {}
UserIterator::~UserIterator() {}

bool UserIterator::hasNext() const {
    if (!room_) return false;
    return idx_ < room_->userCount();
}

User* UserIterator::next() {
    User* u = room_->getUserAt(idx_);
    ++idx_;
    return u;
}

MessageIterator::MessageIterator(const ChatRoom* room) : room_(room), idx_(0) {}
MessageIterator::~MessageIterator() {}

bool MessageIterator::hasNext() const {
    if (!room_) return false;
    return idx_ < room_->historySize();
}

const string& MessageIterator::next() {
    const string& s = room_->getHistoryAt(idx_);
    ++idx_;
    return s;
}
