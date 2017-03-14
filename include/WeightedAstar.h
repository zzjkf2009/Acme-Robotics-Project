/**
*@file WeightedAstar.h
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
*@brief This header define the <WeightedAstar> calss, which is the derive class
*       of the <Astar> class
*/

#ifndef INCLUDE_WEIGHTEDASTAR_H_
#define  INCLUDE_WEIGHTEDASTAR_H_
#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include"Astar.h"

class WeightedAstar : public Astar {
 public:
  std::stack<coordinate> WeightedA(int grid[][COL], coordinate start,
                                   coordinate goal, const int& weight);
};
#endif  // INCLUDE_WEIGHTEDASTAR_H_
