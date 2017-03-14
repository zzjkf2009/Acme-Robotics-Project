/**
*@file BuildingMap.cpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
*@brief This source file defines two functions of <BuildingMap> class
*/
#include <opencv2/opencv.hpp>
#include<cmath>
#include<stack>
#include"BuildingMap.h"
#include<utility>

typedef std::pair<int, int> coordinate;

/**
*@brief Funtion that draw the grid map by using Opencv, walls will be black
*       start and goal node are RGB[0,255,255]
*@param int grid[][], start and goal coordinate
*@return cv::Mat, an image show map including walls, start, goal node
*/
cv::Mat Buildingmap::drawGrids(int grid[ROW][COL], coordinate start,
                               coordinate goal) {
  int image_x = ROW * 10;
  int image_y = COL * 10;
  cv::Mat Background = cv::Mat::zeros(image_x, image_y, CV_8UC3);

  int i, j;
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      if (grid[i][j] == 0)
        continue;
      cv::rectangle(Background, cv::Point(i * 10, j * 10),
                    cv::Point((i + 1) * 10, (j + 1) * 10),
                    cv::Scalar(255, 255, 0), -1, 8);
    }
  }

  int start_i = start.first;
  int start_j = start.second;
  int goal_i = goal.first;
  int goal_j = goal.second;
  cv::rectangle(Background, cv::Point(start_i * 10, start_j * 10),
                cv::Point((start_i + 1) * 10, (start_j + 1) * 10),
                cv::Scalar(0, 255, 255), -1, 8);
  cv::rectangle(Background, cv::Point(goal_i * 10, goal_j * 10),
                cv::Point((goal_i + 1) * 10, (goal_j + 1) * 10),
                cv::Scalar(0, 255, 255), -1, 8);

  return Background;
}

/**
*@brief Funtion that draw the path node which are RGB[0,255,255]
*@param Path nodes in stack <coordinate>, map image Background, in cv::Mat
*@return cv::Mat, an image show map including walls, start, goal node anb path
*/
cv::Mat Buildingmap::drawPath(std::stack<coordinate> Path, cv::Mat Background) {
  while (!Path.empty()) {
    std::pair<int, int> p = Path.top();
    int i = p.first;
    int j = p.second;
    cv::rectangle(Background, cv::Point(i * 10, j * 10),
                  cv::Point((i + 1) * 10, (j + 1) * 10),
                  cv::Scalar(0, 255, 255), -1, 8);
    Path.pop();
  }

  return Background;
}
