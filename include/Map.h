#ifndef MAP_H
#define MAP_H

#include"Astar.h"
#include<utility>

class Map{

public:

int getGridMap(int grid[10][10]);
Astar::coordinate SetStart(const int& x, const int& y);
Astar::coordinate SetGoal(const int& x, const int& y);

};

#endif
