//
// Created by Maxwell on 2020-01-10.
//

#ifndef COMBINATIONLOCK_NODE_H
#define COMBINATIONLOCK_NODE_H


class Node {
public:
    int direction;
    int number;

    Node *next;

    Node() : next(nullptr), direction('R'), number(-1) {}
};


#endif //COMBINATIONLOCK_NODE_H
