/**
 * @file TestingMain.cpp
 * @brief Testing main required for FitchFork. Demonstrates Mediator, Command, Iterator, and Memento.
 */

#include "ChatRoom.h"
#include "User.h"
#include "Iterator.h"
#include "Memento.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== PetSpace TestingMain ===" << endl;

    CtrlCat ctrlcat;
    Dogorithm dogo;

    User name1("Anele");
    User name2("Buhle");
    User name3("Chris");

    name1.joinRoom(&ctrlcat);
    name1.joinRoom(&dogo);
    name2.joinRoom(&ctrlcat);
    name3.joinRoom(&dogo);

    name1.send("Hello CtrlCat! Anyone here?", &ctrlcat);
    name2.send("Hi Anele! Welcome to CtrlCat.", &ctrlcat);
    name1.send("Hey Dogorithm folks, check out my algorithm!", &dogo);
    name3.send("Woof! Nice algorithm, Anele.", &dogo);

    cout << "\nUsers in CtrlCat:" << endl;
    UserIterator uit(&ctrlcat);
    while (uit.hasNext()) {
        User* u = uit.next();
        cout << " - " << u->getName() << endl;
    }

    cout << "\nCtrlCat history:" << endl;
    MessageIterator mit(&ctrlcat);
    while (mit.hasNext()) cout << " * " << mit.next() << endl;

    cout << "\nDogorithm history:" << endl;
    MessageIterator mit2(&dogo);
    while (mit2.hasNext()) cout << " * " << mit2.next() << endl;

    cout << "\n-- Demonstrating Memento --" << endl;
    Memento* snap = dogo.createMemento();
    name3.send("This message will be undone", &dogo);

    cout << "Dogorithm history after extra message:" << endl;
    MessageIterator mit3(&dogo);
    while (mit3.hasNext()) cout << " * " << mit3.next() << endl;

    dogo.restoreMemento(snap);
    dogo.freeMemento(snap);

    cout << "Dogorithm history after restore (undo):" << endl;
    MessageIterator mit4(&dogo);
    while (mit4.hasNext()) cout << " * " << mit4.next() << endl;

    cout << "\n=== End TestingMain ===" << endl;
    return 0;
}
