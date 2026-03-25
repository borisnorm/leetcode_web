/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:

    // é¡ºæ¶é ä¸ å³ ä¸ å·¦, é»è®¤ facing up
    int dir[4][2] = {{1, 0}, {0, 1}, {-1,0}, {0, -1}};
    set<pair<int, int>> visited;
    
    void goBack(Robot& robot)
    {
       robot.turnRight();
       robot.turnRight();
       robot.move();
       robot.turnRight();
       robot.turnRight();
    }

    void dfs(Robot& robot, int x, int y, int dir_idx)
    {
        robot.clean();
        visited.insert({x, y});

        for (int i = 0; i < 4; i++)
        {
           int nd = (dir_idx + i) % 4;
           int nx = x + dir[nd][0];
           int ny = y + dir[nd][1];

           if (!visited.count({nx, ny}) && robot.move())
           {
              dfs(robot, nx, ny, nd);
              goBack(robot);
           }
           // next direction, for loop ä¸ä¼å¸®å®è½¬å
           robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
};