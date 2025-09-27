/**
 * @file DemoMain.cpp
 * @brief Small demo main with simple interactive menu (not required for FitchFork).
 */

#include "ChatRoom.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    CtrlCat ctrlcat;
    Dogorithm dogo;

    User u1("Anele");
    User u2("Buhle");
    User u3("Chris");

    u1.joinRoom(&ctrlcat); u1.joinRoom(&dogo);
    u2.joinRoom(&ctrlcat);
    u3.joinRoom(&dogo);

    cout << "Simple PetSpace Demo (type 'quit' to exit)" << endl;
    string line;
    while (true) {
        cout << "Enter: <user> <room> <message>\nExample: Anele CtrlCat Hello\n> ";
        if (!getline(cin, line)) break;
        if (line == "quit") break;

        size_t pos1 = line.find(' ');
        if (pos1 == string::npos) continue;
        string user = line.substr(0, pos1);

        size_t pos2 = line.find(' ', pos1 + 1);
        if (pos2 == string::npos) continue;
        string room = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string msg = line.substr(pos2 + 1);

        User* pu = nullptr;
        if (user == "Anele") pu = &u1;
        else if (user == "Buhle") pu = &u2;
        else if (user == "Chris") pu = &u3;

        ChatRoom* pr = nullptr;
        if (room == "CtrlCat") pr = &ctrlcat;
        else if (room == "Dogorithm") pr = &dogo;

        if (pu && pr) pu->send(msg, pr);
        else cout << "Unknown user or room." << endl;
    }
    return 0;
}
