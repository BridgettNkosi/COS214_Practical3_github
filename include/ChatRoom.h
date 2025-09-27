/**
 * @file ChatRoom.h
 * @brief ChatRoom mediator interface and concrete chat rooms (CtrlCat, Dogorithm).
 */

#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <vector>
#include <iostream>

class User;
class Memento;   // standalone Memento, not nested inside ChatRoom

class ChatRoom {
public:
    ChatRoom(const std::string &name);
    virtual ~ChatRoom();

    virtual void registerUser(User* user);
    virtual void removeUser(User* user);

    virtual void sendMessage(const std::string &message, User* fromUser);
    virtual void saveMessage(const std::string &message, User* fromUser);

    const std::string& getName() const;

    size_t userCount() const;
    User* getUserAt(size_t idx) const;

    size_t historySize() const;
    const std::string& getHistoryAt(size_t idx) const;

    // Memento support (standalone)
    Memento* createMemento() const;
    void restoreMemento(Memento* m);
    void freeMemento(Memento* m);

protected:
    std::string name_;
    std::vector<User*> users_;
    std::vector<std::string> chatHistory_;
};

class CtrlCat : public ChatRoom {
public:
    CtrlCat();
    virtual ~CtrlCat();
};

class Dogorithm : public ChatRoom {
public:
    Dogorithm();
    virtual ~Dogorithm();
};

#endif // CHATROOM_H
