/**
 * @file User.h
 * @brief User class (Invoker for Command pattern). Users can send messages to ChatRooms
 * and queue commands to be executed.
 */

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class ChatRoom;
class Command;

/**
 * @brief Represents a user in PetSpace. Users can join multiple chat rooms.
 */
class User {
public:
    User(const std::string &name);
    ~User();

    const std::string& getName() const;

    void joinRoom(ChatRoom* room);
    void leaveRoom(ChatRoom* room);

    void send(const std::string &message, ChatRoom* room);
    void receive(const std::string &message, User* fromUser, ChatRoom* room);

    // Command queue operations
    void addCommand(Command* cmd);
    void executeAll();

private:
    std::string name_;
    std::vector<ChatRoom*> chatRooms_;
    std::vector<Command*> commandQueue_;
};

#endif // USER_H
