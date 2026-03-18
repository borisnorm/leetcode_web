class Solution {
public:
    int totalWays;
    int uniquePathsIII(vector<vector<int>>& grid) {
        
         if (grid.empty() || grid[0].empty())
           return 0;

         int m = grid.size();
         int n = grid[0].size();

         int end_x = 0;
         int end_y = 0;
         int start_x = 0;
         int start_y = 0;
         int total = 0;
         for(int i = 0; i < m; i++)
         {
           for (int j = 0; j < n; j++)
           {
              if (grid[i][j] == 1)
              {
                 start_x = i;
                 start_y = j;
              }
              
              if (grid[i][j] == 2)
              {
                 end_x = i;
                 end_y = j;
              }
              
              if (grid[i][j] != -1)
                total++;
           }
         }
        
         int step = 1;
         dfs(grid, start_x, start_y, end_x, end_y, step, total);
         return totalWays;
    }
      void dfs(vector<vector<int>>& grid, int x, int y, int end_x, int end_y, int step, int totalStep)
      {

         int m = grid.size();
         int n = grid[0].size();
         if (x < 0 || x >= m || y < 0 || y >= n)
           return ;

         if (x == end_x && y == end_y)
         {
            if (step == totalStep)
              totalWays++;
            
            return;
         }

         vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

         grid[x][y] = - 1;
         for (auto dir : dirs)
         { 
           int nx = x + dir.first;
           int ny = y + dir.second;

           if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
                
           if (grid[nx][ny] == -1)
             continue;

           dfs(grid, nx, ny, end_x, end_y, step+1, totalStep);
        }
        //回溯
        grid[x][y] = 0;
    }
};