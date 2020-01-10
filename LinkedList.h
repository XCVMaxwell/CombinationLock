#ifndef COMBINATIONLOCK_LINKEDLIST_H
#define COMBINATIONLOCK_LINKEDLIST_H

#include "Node.h"

using namespace std;

class LinkedList {
private:
    Node* first;

public:
    LinkedList();

    virtual ~LinkedList();

    void Add(char direction, int number);

    void DeleteValue(char direction, int number);

    void DeleteNode(int indexToDelete);

    void InsertAfterValue(char direction, int number, char prevDirection, int prevNumber);

    void InsertBeforeNode(int nodeIndex, char direction, int number);

    friend ostream& operator<<(ostream& output, LinkedList& list);
};


#endif //COMBINATIONLOCK_LINKEDLIST_H
