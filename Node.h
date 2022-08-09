#pragma once
#include<list>
#include <iostream>
class Node {
public:
    std::list<Node*> neighbors;
    std::string name;
    bool visited = false;
    Node* prev = nullptr;

    Node(std::string name) { 
        this->name = name; 
    }

    void addNeighbour(Node* v) {
        this->neighbors.push_back(v);
        v->neighbors.push_back(this);
    }
};
