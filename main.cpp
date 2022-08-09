#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "User.h"
#include <vector>
#include "Node.h"
#include "BFS.h"

std::vector < User > allUsers;
int getID(std::string name)
{
    for (int i = 0; i < allUsers.size(); i++)
    {
        if (" "+allUsers[i].name == name)
        {
            return allUsers[i].ID;

        }

    }
}

User getUserbyID(int id) {

    for (int i = 0; i < allUsers.size(); i++)
    {
        if (allUsers[i].ID == id)
        {
            return allUsers[i];

        }

    }

}

int main()
{
    

    std::fstream file;
    file.open("data.txt", std::ios::in);

    if (file.good() == false) std::cout << "Cant open the file!";

    std::string line;
    int temp = 0;
    while ((getline(file, line)))
    {
        std::stringstream  linestream(line);
        std::string value;
        User user;
        allUsers.push_back(user);
        int temp2 = 0;
        allUsers[temp].ID = temp;
        while (getline(linestream, value, ','))
        {
            if (temp2 == 0)
                allUsers[temp].name = value;
            else
                allUsers[temp].friendsNames.push_back(value);
            temp2++;
        }
        temp++;
    }

    for (int i = 0; i < allUsers.size(); i++)
    {
        for (int j = 0; j < allUsers[i].friendsNames.size(); j++)
        {
            allUsers[i].friendsIDs.push_back(getID(allUsers[i].friendsNames[j]));

        }

    }

    file.close();

    std::vector < Node > NodesVector;
    
    for (int i = 0; i < allUsers.size(); i++)
    {
        NodesVector.push_back(Node(allUsers[i].name));
        
    }
    for (int i = 0; i < NodesVector.size(); i++)
    {
        for (int j = 0; j < allUsers[i].friendsIDs.size(); j++)
        {
            NodesVector[i].addNeighbour(&NodesVector[allUsers[i].friendsIDs[j]]);
        }

    }
    
    BFS bfs(&NodesVector[2], &NodesVector[6]);
    bfs.findPath();
    return 0;
}


