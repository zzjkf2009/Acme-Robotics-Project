#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include"Astar.h"
#include<cmath>
/////////////////////////////
typedef std::pair<int, int> coordinate;
///////////////////////////////////

/*@ define a data structure contains some parameters that a node may have */


/*@  function to check if the input coordinate is inside the grid map*/
bool Astar::isValid(const int& x, const int& y) {

return ((x>=0)&&(x<ROW)&&(y>=0)&&(y<COL));

}

/*@  function to check if the grid is a block or wall something like that*/
bool Astar::isUnblocked(int grid[][COL], const int& x, const int& y) {

if (grid[x][y]==1)
return true;
else
return false;

}

/*@  funtion to check if it is the goal node */
bool Astar::isGoalNode(const int& x, const int& y, coordinate goal) {

if (x == goal.first && y == goal.second)
return true;
else
return false;
}

/*@  function to calculate the heuristic value between current node and goal node
 method usd here is Eucliden Distance. Other method like Diagnal Distance or Manhattan Distance are also
 appliable */

double Astar::calculate_H(const int& x, const int& y, coordinate goal) {

return ((double) sqrt(
  (x - goal.first) * (x - goal.first) + (y - goal.second) * (y - goal.second)));

}

/*@ function that will generate the path back from goal node to the start node
 and the path of the nodes will displayed on the screen */

std::stack <coordinate> Astar::GeneratePath(node nodepath[][COL], coordinate goal) {

printf("The path is  \n");

int x = goal.first;
int y = goal.second;

std::stack < coordinate > Path;
//////////////////////////////////////////////
std::stack < coordinate > PathOut;
////////////////////////////////////////////
while(!(nodepath[x][y].parent_x==x && nodepath[x][y].parent_y==y)) {

Path.push(std::make_pair(x,y));
int temp_x= nodepath[x][y].parent_x;
int temp_y=nodepath[x][y].parent_y;
x=temp_x;
y=temp_y;
}
Path.push(std::make_pair(x, y));
/////////////////////////////////
PathOut = Path;
//////////////////////////////
while (!Path.empty()) {

std::pair<int, int> p = Path.top();
Path.pop();
printf("---->>>> (%d,%d) ", p.first, p.second);

}

return PathOut;
}

//std::stack <coordinate> Astar::WeightedAstar(int grid[][COL], coordinate start, coordinate goal,
//                          const int& weight) {
//
//if (isValid(start.first, start.second) == false) {
//
//printf("start node is invalid\n");
//return{};
//}
//
//if (isValid(goal.first, goal.second) == false) {
//
//
//printf("Goal node is invalid");
//return{};
//}
//
//if (isUnblocked(grid, start.first, start.second) == false
//  || isUnblocked(grid, goal.first, goal.second) == false) {
//
//printf("Start or gaol node is blocked");
//return{};
//
//}
//
//if (isGoalNode(start.first, goal.second, goal) == true) {
//
//
//printf("Start node and goal node are same");
//return{};
//}
//
///*@ Create a close list and initial it to f*/
//bool closedList[ROW][COL];
//memset(closedList, false, sizeof(closedList));
//
//node nodeinfo[ROW][COL];
//
///*@ Declare a array to hold the info of every nodes*/
//int i, j;
//
//for (i = 0; i < ROW; i++) {
//for (j = 0; j < COL; j++) {
//
//  nodeinfo[i][j].F = FLT_MAX;
//  nodeinfo[i][j].H = FLT_MAX;
//  nodeinfo[i][j].G = FLT_MAX;
//  nodeinfo[i][j].parent_x = -1;
//  nodeinfo[i][j].parent_y = -1;
//}
//}
//
///*@ initialising the parameters of the starting node*/
//
//i = start.first;
//j = start.second;
//
//nodeinfo[i][j].F = 0.0;
//nodeinfo[i][j].H = 0.0;
//nodeinfo[i][j].G = 0.0;
//nodeinfo[i][j].parent_x = i;
//nodeinfo[i][j].parent_y = j;
//
///*@ Create a open List which has the info of <F, <i,j>>
// where f=G+weight*H    */
//
//std::set < Open_list > openList;
//
///* put start node into openList*/
//openList.insert(std::make_pair(0.0, std::make_pair(i, j)));
//
//bool foundGoal = false;
//
//while (!openList.empty()) {
//
//Open_list p = *openList.begin();
//
//openList.erase(openList.begin());
//i = p.second.first;
//j = p.second.second;
//closedList[i][j] = true;
///* Generating all of the 8 sucessor node around the current node */
//double Gnew, Hnew, Fnew;
//std::vector<int> sucessor_x = { -1, 0, 1 };
//std::vector<int> sucessor_y = { -1, 0, 1 };
//// For every node near the current node, top, top-left, top-right, left, right,
//// bottom, bottom-left, bottom-right
//
//////////////////////
//std::stack < coordinate > PathOut;
///////////////////////////////
//
//for (int k : sucessor_x) {
//  for (int l : sucessor_y) {
//    if (k == 0 && l == 0)
//      continue;
//    if (isValid(i + l, j + k) == true) {
//      if (isGoalNode(i + k, j + l, goal) == true) {
//        nodeinfo[i + k][j + l].parent_x = i;
//        nodeinfo[i + k][j + l].parent_y = j;
//        std::printf("The goal node is found\n");
//		PathOut=GeneratePath(nodeinfo,goal);
//        foundGoal = true;
//        return PathOut;
//      } else if (closedList[i + k][j + l] == false
//          && isUnblocked(grid, i + k, j + l) == true) {
//        Gnew = nodeinfo[i][j].G + sqrt(k * k + l * l);
//        Hnew = calculate_H(i + k, j + l, goal);
//        Fnew = Gnew + weight*Hnew;
//        if (nodeinfo[i + k][j + l].F == FLT_MAX
//            || nodeinfo[i + k][j + l].F > Fnew) {
//          openList.insert(std::make_pair(Fnew, std::make_pair(i + k, j + l)));
//          nodeinfo[i + k][j + l].F = Fnew;
//          nodeinfo[i + k][j + l].G = Gnew;
//          nodeinfo[i + k][j + l].H = Hnew;
//          nodeinfo[i + k][j + l].parent_x = i;
//          nodeinfo[i + k][j + l].parent_y = j;
//
//        }
//
//      }
//    }
//  }
//}
//}
//
//if (foundGoal == false)
//printf(" Failed to find th goal node");
//return{} ;
//}
