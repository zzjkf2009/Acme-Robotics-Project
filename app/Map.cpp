#include"Map.h"
#include"Astar.h"
#include<utility>



int Map::getGridMap(int grid[10][10]){

return grid[10][10];

}

Astar::coordinate Map::SetStart(const int& x, const int& y){

  return std::make_pair(x,y);


}

Astar::coordinate Map::SetGoal(const int& x, const int& y){

  return std::make_pair(x,y);


}
