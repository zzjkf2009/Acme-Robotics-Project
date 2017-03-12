#ifndef BUILDINGMAP_H
#define BUILDINGMAP_H
#include <opencv2/opencv.hpp>
#include<cmath>
#include<stack>

#define ROW 10
#define COL 10

class Buildingmap{

public:
typedef std::pair<int, int> coordinate;
cv::Mat drawGrids(int grid[ROW][COL],coordinate start, coordinate goal);
cv::Mat drawPath(std::stack < coordinate > Path, cv::Mat Background);





};

#endif
