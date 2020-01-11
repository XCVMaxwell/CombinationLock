#ifndef COMBINATIONLOCK_LINKEDLIST_H
#define COMBINATIONLOCK_LINKEDLIST_H

#include "Node.h"

using namespace std;

class LinkedList {
public:

    Node* first;
    LinkedList();

    virtual ~LinkedList();

    void Add(int number);

    void DeleteValue(int number);

    void DeleteNode(int indexToDelete);

    void InsertAfterValue(int number, int prevNumber);

    void InsertBeforeNode(int nodeIndex, int number);

    void ChangeValue(int nodeIndex, int newNumber);

    friend ostream& operator<<(ostream& output, LinkedList& list);
};


#endif //COMBINATIONLOCK_LINKEDLIST_H
