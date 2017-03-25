#include "Map.h"
#include <iostream>
using namespace std;



Map::Map(std::string startLocationName)
{
	CurrentLocation = new Location(startLocationName, 0, 0);
	std::string hash = "(0,0)";
	_mapLookup[hash] = CurrentLocation;

}


Map::~Map()
{
}

void Map::Move(Location *newLocation)
{
	_locationsVisited.push(newLocation);
	CurrentLocation = newLocation;
}

Location * Map::LookupLocationOnMap(int x, int y)
{
	std::string hash = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
	return _mapLookup[hash];
}

std::string Map::GetPathBackToHome()
{
	std::string path;
	

	while (!_locationsVisited.empty())
	{
	    
		path += _locationsVisited.top()->DisplayLocationInfo();
		_locationsVisited.pop();
	}
	

	

	return "To get back home just follow this path: " + path;
}