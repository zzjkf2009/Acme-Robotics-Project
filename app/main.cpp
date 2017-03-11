#include <iostream>
#include "Astar.h"
#include<set>
#include<vector>
#include<stack>

int main()
{
  typedef std::pair<int, int> coordinate;
    /* set the grid map
    1 stands for walkable path
    0 stands for blocked walls */
    int grid[9][10]=
    {
       {1,0,1,1,1,1,0,1,1,1},
       {1,1,1,0,1,1,1,0,1,1},
       {1,1,1,0,1,1,0,1,0,1},
       {0,0,1,0,1,0,0,0,0,1},
       {1,1,1,0,1,1,1,0,1,0},
       {1,0,1,1,1,1,1,0,1,0},
       {1,0,1,0,1,1,0,1,1,0},
       {1,1,1,0,0,1,0,0,1,1},
       {0,0,1,1,0,1,1,1,0,1}
    };
    /* Set the start and goal node */

    coordinate start=std::make_pair(0,0);
    coordinate goal=std::make_pair(8,9);
    int weight=1;
    Astar w_astar;
    w_astar.WeightedAstar(grid,start,goal,weight);
    std::cin.get();
    return 0;
}
