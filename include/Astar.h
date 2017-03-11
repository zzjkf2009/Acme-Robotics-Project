
#ifndef ASTAR_H
#define ASTAR_H


#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include<cmath>
#include<cstring>

class Astar {

private:

#define ROW 9
#define COL 10
#define FLT_MAX 3.4e+38F
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
  void GeneratePath(node nodepath[][COL], coordinate goal);

public:

void WeightedAstar(int grid[][COL], coordinate start, coordinate goal,const int& weight);

};


#endif
