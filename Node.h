#pragma once
#include<list>
#include <iostream>
class Node {
public:
    //Adjacency List of the vertex
    std::list<Node*> neighbors;
    std::string name;
    bool visited = false;
    Node* prev = nullptr;

    Node(std::string name) { 
        this->name = name; 
    }

    //Method to connect vertices
    void addNeighbour(Node* v) {
        this->neighbors.push_back(v);
        v->neighbors.push_back(this);
    }
};
