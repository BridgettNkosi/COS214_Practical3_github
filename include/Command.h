/**
 * @file Command.h
 * @brief Command pattern base class and concrete commands:
 * SendMessageCommand and SaveMessageCommand.
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class ChatRoom;
class User;

/**
 * @brief Abstract Command interface
 */
class Command {
public:
    Command(ChatRoom* room, User* from, const std::string &message);
    virtual ~Command();
    virtual void execute() = 0;

protected:
    ChatRoom* room_;
    User* fromUser_;
    std::string message_;
};

/**
 * @brief SendMessageCommand delivers message to users via ChatRoom::sendMessage.
 */
class SendMessageCommand : public Command {
public:
    SendMessageCommand(ChatRoom* room, User* from, const std::string &message);
    virtual ~SendMessageCommand();
    virtual void execute();
};

/**
 * @brief SaveMessageCommand appends the message to chat history via ChatRoom::saveMessage.
 */
class SaveMessageCommand : public Command {
public:
    SaveMessageCommand(ChatRoom* room, User* from, const std::string &message);
    virtual ~SaveMessageCommand();
    virtual void execute();
};

#endif // COMMAND_H
