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
        //Create queue and declare variables
        std::queue<Node*> Queue;
        bool reached_end = false;
        //Visit start node and add to queue
        start->visited = true;
        Queue.push(start);

        //BFS until queue is empty
        while (!Queue.empty() && !reached_end) {
            //Pop a node from queue for search operation
            Node* current_node = Queue.front();
            Queue.pop();
            //Loop through neighbors nodes to find the 'end' node
            for (Node* node : current_node->neighbors) {
                if (!node->visited) {
                    //Visit and add neighbor nodes to the queue
                    node->visited = true;
                    Queue.push(node);
                    node->prev = current_node;
                    //stop BFS if the end node is found
                    if (node == end) {
                        reached_end = true;
                        break;
                    }
                }
            }
        }
        trace_route();
    }

    //Function to trace back route
    void trace_route() {
        std::list<Node*> route;
        Node* node = end;
        //start.prev is always null 
        //so loop until node->prev is null to trace route
        while (node != nullptr) {
            route.push_front(node);
            node = node->prev;
        }

        //Display the route
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