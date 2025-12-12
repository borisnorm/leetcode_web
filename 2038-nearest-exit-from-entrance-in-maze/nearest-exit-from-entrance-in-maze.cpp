class Solution {
public:
    int ans = 0;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       int m = maze.size();
       int n = maze[0].size();

       int entrance_row = entrance[0];
       int entrance_col = entrance[1];

       vector<pair<int, int>> dirs = {
         {-1, 0},
         {1, 0},
         {0, 1},
         {0, -1}
       };

       queue<tuple<int, int, int>> q;

       q.push({entrance_row, entrance_col, 0});
       maze[entrance_row][entrance_col] = '+';

       while (!q.empty())
       {
          auto [r, c, steps] = q.front();
          q.pop();

          for (auto& d: dirs)
          {
             int nr = r + d.first;
             int nc = c + d.second;

             if (nr < 0 || nr >= m || nc < 0 || nc >= n)
               continue;
            
             if (maze[nr][nc] == '+')
               continue;
            
             if (nr == 0 || nr == m - 1 || nc == 0 || nc == (n - 1))
                return steps + 1;

             maze[nr][nc] = '+';
             q.push({nr, nc, steps + 1});
          }
       }

       return -1;
    }
};