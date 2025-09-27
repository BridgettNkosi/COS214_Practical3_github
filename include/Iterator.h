/**
 * @file Iterator.h
 * @brief Simple Iterator implementations for Users and Chat History.
 */

#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include <string>

class User;
class ChatRoom;

/**
 * @brief Iterates over users in a ChatRoom.
 */
class UserIterator {
public:
    UserIterator(const ChatRoom* room);
    ~UserIterator();

    bool hasNext() const;
    User* next();

private:
    const ChatRoom* room_;
    size_t idx_;
};

/**
 * @brief Iterates over message history in a ChatRoom.
 */
class MessageIterator {
public:
    MessageIterator(const ChatRoom* room);
    ~MessageIterator();

    bool hasNext() const;
    const std::string& next();

private:
    const ChatRoom* room_;
    size_t idx_;
};

#endif // ITERATOR_H
