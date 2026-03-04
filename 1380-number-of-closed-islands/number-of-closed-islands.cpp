class Solution {
public:
    // DFS 解法
    // Time: O(m x n)
    // Space: O(m x n)
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
          return 0;

        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        //dfs 的作用是染色
        // 1. 4边染色, 但是不做 cnt++ 
        //    如果去掉 4边染色, 直接进行 dfs, 
        //    那么在判断 grid[i][j] == 0的时候, 会错误的 count 边界上的 0, 
        //    因为 边界上的 0 不能算是 closed island
        for (int i = 0; i < m; i++)
        {
          // the most left and most right col
          if (grid[i][0] == 0)
             dfs(grid, i, 0);

          if (grid[i][n-1] == 0)
            dfs(grid, i, n-1);    
        }

        for (int j = 0 ; j < n; j++)
        {
          // the top and bottom row
          if (grid[0][j] == 0)
             dfs(grid, 0, j);
        
          if (grid[m-1][j] == 0)
             dfs(grid, m-1, j);
        }
        
        
        // 2.统计 island 岛屿
        for (int i = 0; i < m; i++)
         for (int j = 0; j < n; j++)
           if (grid[i][j] == 0)
           {
             cnt++;
             dfs(grid, i, j);
           }

        return cnt;
    }

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
       int m = grid.size();
       int n = grid[0].size();

       if (i < 0 ||i >= m || j < 0 || j >= n) 
         return;

       // 题目要求 0 才是岛屿
       if (grid[i][j] != 0)
         return;

       // 染色为 1 , 因为 1不是岛屿
       grid[i][j] = 1;

       dfs(grid, i, j-1);
       dfs(grid, i, j+1);
       dfs(grid, i-1, j);
       dfs(grid, i+1, j);
    }
};