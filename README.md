# COS214 Practical 3 – PetSpace Chat System

##  Overview
PetSpace is a simple **chat room simulation** built in C++ that demonstrates the use of **design patterns**.  
The system allows multiple users to join different chat rooms, send messages, browse chat history, and even undo changes using snapshots.

This project was developed as part of the COS214 course at the **University of Pretoria**.

---

##  Features
- Users can join multiple chat rooms.
- Users can send messages to specific chat rooms.
- Chat rooms keep message history.
- **Undo/restore functionality** via the Memento pattern.
- Iterators to traverse users and chat history.
- Extensible command-based operations for sending/saving.

---

##  Design Patterns Implemented
### 1. Mediator  
- **Purpose**: Decouples direct communication between users.  
- **In Code**: `ChatRoom` acts as the Mediator, routing messages between `User` objects.  
- **Analogy**: Like an air traffic control tower that coordinates planes.

### 2. Command  
- **Purpose**: Encapsulates operations (send, save) as command objects.  
- **In Code**: `SendMessageCommand` and related classes.  
- **Analogy**: Remote control buttons, each executing a specific action.

### 3. Iterator  
- **Purpose**: Provides sequential access to collections without exposing internal structures.  
- **In Code**: `UserIterator` (iterate over users) and `MessageIterator` (iterate over chat history).  
- **Analogy**: Browsing a library catalog instead of digging into shelves.

### 4. Memento  
- **Purpose**: Captures and restores an object’s state.  
- **In Code**: `Memento` stores chat history, `ChatRoom` restores from snapshots.  
- **Analogy**: Ctrl+Z (Undo) in Word or Photoshop.

---

## Build & Run
### Prerequisites
- Linux / WSL / macOS / or MinGW on Windows
- `g++` with C++11 support
- `make`

### Build & Run (Testing Main)
```bash
make run

