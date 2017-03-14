/**
*@file test.cpp
*@Author Zejiang Zeng
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
*@brief This source file define three google unit test for the Astar palth
*       planing project
*/
#include <gtest/gtest.h>
#include<utility>
#include<stack>
#include"Astar.h"
#include"../app/Astar.cpp"
#include"WeightedAstar.h"
#include"../app/WeightedAstar.cpp"


typedef std::pair<int, int> coordinate;
Astar Testastar;
WeightedAstar TestWeightA;
/**
*@brief This test is to verify if the given node (40,90) is valid for that
         10 by 10 grid map, it should get false (0), since is beyond the map
*/
TEST(Astartest, map_contrain) {
  EXPECT_EQ(Testastar.isValid(40, 90), 0);
}

/**
*@brief This test is to verify if the given node is the goal node, since
*       given and goal node are both (8,9). It should get ture
*/
TEST(Astartest, testGoal) {
  coordinate goal = std::make_pair(8, 9);
  EXPECT_EQ(Testastar.isGoalNode(8, 9, goal), 1);
}
/**
*@brief This is to check if grid map and start, goal node are given, the path
*       planning function should give a path, and it is no empty, since we
*       know there is a pgysibal solution before run the program
*/
TEST(Astartest, AstarAlgorithm) {
/*  int grid[10][10]=
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
  }; */
  int grid[10][10] = { { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, { 1, 1, 1, 0, 1, 1, 1,
      0, 1, 1 }, { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, { 0, 0, 1, 0, 1, 0, 0, 0, 0,
      1 }, { 1, 1, 1, 0, 0, 1, 1, 0, 1, 0 }, { 1, 0, 1, 1, 0, 1, 1, 0, 1, 0 }, {
      1, 0, 1, 0, 0, 1, 0, 1, 1, 0 }, { 1, 1, 1, 0, 0, 1, 0, 0, 1, 1 }, { 0, 0,
      1, 1, 0, 1, 1, 1, 0, 1 }, { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0 } };
  coordinate start = std::make_pair(0, 0);
  coordinate goal = std::make_pair(8, 9);
  std::stack<coordinate> TestPath;
  int weight = 5;
  TestPath = TestWeightA.WeightedA(grid, start, goal, weight);
  EXPECT_NE(TestPath.empty(), 1);
}
