#pragma once
#include <stack>
#include "Location.h"
#include <unordered_map>

class Map
{
private:
	std::stack<Location *> _locationsVisited;
	std::unordered_map<std::string, Location *> _mapLookup;
	
public:
	Map(std::string startLocationName);
	~Map();

	Location * CurrentLocation = nullptr;
	std::string GetPathBackToHome();
	void Move(Location *newLocation);
	Location * LookupLocationOnMap(int x, int y);
};

