#pragma once
#include <iostream>
#include <vector>

class User
{
public:
	int ID;
	std::string name;
	std::vector < std::string > friendsNames;
	std::vector < int > friendsIDs;

};

