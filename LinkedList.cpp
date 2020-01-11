#include <iosfwd>
#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() : first(nullptr) {}

LinkedList::~LinkedList() {
    Node* node = first;

    while (node != nullptr) {
        Node* temp = node;

        node = node->next;

        delete temp;
    }
}

void LinkedList::Add(int number) {
    Node* node = new Node();
    node->number = number;

    if (first == nullptr) {
        first = node;
    }
    else {
        Node* currNode = first;
        Node* prevNode = nullptr;

        while (currNode != nullptr) {
            prevNode = currNode;
            currNode = currNode->next;
        }

        if (prevNode != nullptr)
            prevNode->next = node;
    }
}

void LinkedList::DeleteValue(int number) {
    Node* node = first;
    Node* prev = nullptr;

    while (node != nullptr) {
        if (node->number == number)
            break;

        prev = node;
        node = node->next;
    }

    if (node != nullptr) {
        if (node == first)
            first = node->next;
        else
            prev->next = node->next;

        delete node;
    }
}

void LinkedList::DeleteNode(int indexToDelete) {
    int index = -1;

    Node* node = first;
    Node* prev = nullptr;

    while (node != nullptr) {
        index++;

        if (index == indexToDelete)
            break;

        prev = node;
        node = node->next;
    }

    if (index >= 0) {
        if (node == first)
            first = node->next;
        else
            prev->next = node->next;

        delete node;
    }
}

void LinkedList::InsertAfterValue(int number, int prevNumber) {
    Node* node = new Node();
    node->number = number;

    Node* prev = first;

    while (prev != nullptr) {
        if (prev->number == prevNumber)
            break;

        prev = prev->next;
    }

    if (first == nullptr) {
        first = node;
    }
    else {
        if (prev != nullptr) {
            node->next = prev->next;
            prev->next = node;
        }
        else {
            Add(number);
        }
    }
}

void LinkedList::InsertBeforeNode(int nodeIndex, int number) {
    int index = -1;

    Node* newNode = new Node();
    newNode->number = number;

    Node* node = first;
    Node* prev = nullptr;

    while (node != nullptr) {
        index++;

        if (index == nodeIndex)
            break;

        prev = node;
        node = node->next;
    }

    if (first == nullptr) {
        first = newNode;
    }
    else {
        if (node != nullptr) {
            prev->next = newNode;
            newNode->next = node;
        }
        else {
            Add(number);
        }
    }
}

void LinkedList::ChangeValue(int nodeIndex, int newNumber) {
    int index = -1;

    Node* node = first;

    while (node != nullptr) {
        index++;

        if (index == nodeIndex) {
            node->number = newNumber;
            break;
        }

        node = node->next;
    }
}

ostream& operator<<(ostream& output, LinkedList& list) {
    Node* currNode = list.first;

    while (currNode != nullptr) {
        output << currNode->number << endl;

        currNode = currNode->next;
    }

    return output;
}
