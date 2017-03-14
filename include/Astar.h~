
#ifndef ASTAR_H
#define ASTAR_H


#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include<cmath>
#include<cstring>

class Astar {

public:

#define ROW 10
#define COL 10
#define FLT_MAX __FLT_MAX__
struct node {

  int parent_x;
  int parent_y;
  double F, H, G;
};
  typedef std::pair<int, int> coordinate;
  typedef std::pair<double, std::pair<int, int> > Open_list;

  bool isValid(const int& x, const int& y);
  bool isUnblocked(int grid[][COL], const int& x, const int& y);
  bool isGoalNode(const int& x, const int& y, coordinate goal);
  double calculate_H(const int& x, const int& y, coordinate goal);
  std::stack < coordinate > GeneratePath(node nodepath[][COL], coordinate goal);
  std::stack < coordinate > WeightedAstar(int grid[][COL], coordinate start, coordinate goal,const int& weight);

};


#endif
