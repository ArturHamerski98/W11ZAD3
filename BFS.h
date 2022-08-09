#pragma once
#include "Node.h"
#include <iostream>
#include <queue>
#include<list>
class BFS {
    Node* start;
    Node* end;

public:
    BFS(Node* start, Node* end) {
        this->start = start;
        this->end = end;
    }

    void findPath() {
        std::queue<Node*> Queue;
        bool reached_end = false;
        start->visited = true;
        Queue.push(start);

        while (!Queue.empty() && !reached_end) {
            Node* current_node = Queue.front();
            Queue.pop();
            for (Node* node : current_node->neighbors) {
                if (!node->visited) {
                    node->visited = true;
                    Queue.push(node);
                    node->prev = current_node;
                    if (node == end) {
                        reached_end = true;
                        break;
                    }
                }
            }
        }
        trace_route();
    }

    void trace_route() {
        std::list<Node*> route;
        Node* node = end;
        while (node != nullptr) {
            route.push_front(node);
            node = node->prev;
        }

     
        int routeSize = route.size();
        int temp = 0;
        for (Node* n : route) {
            if (temp < routeSize-1)
                std::cout << n->name << "--> ";
            else
                std::cout << n->name << "\nMinimum distance between two users: "<<routeSize-1;
            temp++;
        }
    }

};