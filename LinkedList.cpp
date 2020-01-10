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

void LinkedList::Add(char direction, int number) {
    Node* node = new Node();
    node->direction = direction;
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

void LinkedList::DeleteValue(char direction, int number) {
    Node* node = first;
    Node* prev = nullptr;

    while (node != nullptr) {
        if (node->direction == direction && node->number == number)
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

void LinkedList::InsertAfterValue(char direction, int number, char prevDirection, int prevNumber) {
    Node* node = new Node();
    node->direction = direction;
    node->number = number;

    Node* prev = first;

    while (prev != nullptr) {
        if (prev->direction == prevDirection && prev->number == prevNumber)
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
            Add(direction, number);
        }
    }
}

void LinkedList::InsertBeforeNode(int nodeIndex, char direction, int number) {
    int index = -1;

    Node* newNode = new Node();
    newNode->direction = direction;
    newNode->number = number;

    Node* node = first;
    Node* prev = first;

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
            Add(direction, number);
        }
    }
}

ostream& operator<<(ostream& output, LinkedList& list) {
    Node* currNode = list.first;

    while (currNode != nullptr) {
        output << "Combination = " << currNode->direction << currNode->number << endl;

        currNode = currNode->next;
    }

    return output;
}
