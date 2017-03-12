#include <iostream>
#include "Astar.h"
#include<set>
#include<vector>
#include<stack>
#include"BuildingMap.h"
#include <opencv2/opencv.hpp>

int main()
{
  typedef std::pair<int, int> coordinate;
    /* set the grid map
    1 stands for walkable path
    0 stands for blocked walls */
    int grid[10][10]=
    {
       {1,0,1,1,1,1,0,1,1,1},
       {1,1,1,0,1,1,1,0,1,1},
       {1,1,1,0,1,1,0,1,0,1},
       {0,0,1,0,1,0,0,0,0,1},
       {1,1,1,0,0,1,1,0,1,0},
       {1,0,1,1,0,1,1,0,1,0},
       {1,0,1,0,0,1,0,1,1,0},
       {1,1,1,0,0,1,0,0,1,1},
       {0,0,1,1,0,1,1,1,0,1},
       {0,1,0,0,1,1,0,0,1,0}
    };
    /* Set the start and goal node */

    coordinate start=std::make_pair(0,0);
    coordinate goal=std::make_pair(8,9);
    std::stack < coordinate > Path;
    int weight=5;
    Astar w_astar;
    Path=w_astar.WeightedAstar(grid,start,goal,weight);
    Buildingmap build;
    cv::Mat Map=build.drawGrids(grid,start,goal);
    cv::Mat PathIm=build.drawPath(Path,Map);

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
    cv::imshow("Display Image", PathIm);

    std::cin.get();
    return 0;
}
