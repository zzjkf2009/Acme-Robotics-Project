#ifndef WEIGHTEDASTAR_H
#define  WEIGHTEDASTAR_H
#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include"Astar.h"

class WeightedAstar: public Astar {

public:

	std::stack <coordinate> WeightedA(int grid[][COL], coordinate start, coordinate goal, const int& weight);



};
#endif