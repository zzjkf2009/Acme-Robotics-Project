#include <gtest/gtest.h>
#include"Astar.h"
#include"../app/Astar.cpp"
#include"WeightedAstar.h"
#include"../app/WeightedAstar.cpp"

typedef std::pair<int, int> coordinate;

Astar Testastar;
WeightedAstar TestWeightA;

TEST(Astartest, map_contrain){


EXPECT_EQ(Testastar.isValid(40,90),0);

}



TEST(Astartest, testGoal){

  coordinate goal=std::make_pair(8,9);
  EXPECT_EQ(Testastar.isGoalNode(8,9,goal),1);
}

TEST(Astartest, AstarAlgorithm){

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

  coordinate start=std::make_pair(0,0);
  coordinate goal=std::make_pair(8,9);
  std::stack < coordinate > TestPath;
  int weight=5;
  TestPath=TestWeightA.WeightedA(grid,start,goal,weight);
  EXPECT_NE(TestPath.empty(),1);

}
