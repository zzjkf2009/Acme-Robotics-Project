/**
*@file main.cpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
*@brief This is the main funtion for this mid-term peoject, it
*        reads the user defined grid map to determine an optimal
*        path from start to goal node
*@return the path from start to goal node will be displayed on the screen
*        and map with path will be showed in a image
*/
#include <opencv2/opencv.hpp>
#include <iostream>
#include<set>
#include<vector>
#include<stack>
#include"BuildingMap.h"
#include"WeightedAstar.h"
#include"Map.h"
#include "Astar.h"


int main() {
    /* set the grid map:
    1 stands for walkable path
    0 stands for blocked walls
    format below is a user frendly format to let user understand
    the map easier.
       int grid[10][10]=
    {
       {1,1,1,1,1,1,1,1,1,1},
       {1,1,0,0,0,0,0,0,1,1},
       {1,1,1,1,1,1,1,0,1,1},
       {1,1,1,1,1,1,1,0,1,1},
       {1,1,1,1,1,1,1,0,1,1},
       {1,1,1,1,1,1,1,0,1,1},
       {1,1,1,1,1,1,1,0,1,1},
       {1,1,0,0,0,0,0,0,1,1},
       {1,1,1,1,1,1,1,1,1,1},
       {1,1,1,1,1,1,1,1,1,1}
    }; */
    int grid[10][10] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 0, 0, 0, 0,
      0, 0, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 0,
      1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 0, 1, 1
      }, { 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 }, { 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
    /* Set the start and goal node */
  Map setmap;
  Astar::coordinate start = setmap.SetStart(5, 4);
  Astar::coordinate goal = setmap.SetGoal(9, 5);
  std::stack<Astar::coordinate> Path;
  int weight = 5;
  WeightedAstar w_astar;
  Path = w_astar.WeightedA(grid, start, goal, weight);
  Buildingmap build;
  cv::Mat Map = build.drawGrids(grid, start, goal);
  cv::Mat PathIm = build.drawPath(Path, Map);
  cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
  cv::imshow("Display Image", PathIm);
  std::cin.get();
  return 0;
}
