/**
 * @file Memento.h
 * @brief Memento pattern helper for ChatRoom to save/restore chat history.
 */

#ifndef MEMENTO_H
#define MEMENTO_H

#include <vector>
#include <string>

/**
 * @brief Memento stores a snapshot of chat history.
 */
class Memento {
public:
    Memento(const std::vector<std::string> &state) : state_(state) {}
    ~Memento() {}

    const std::vector<std::string>& getState() const { return state_; }

private:
    std::vector<std::string> state_;
};

#endif // MEMENTO_H
