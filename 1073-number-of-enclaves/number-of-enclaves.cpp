class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         if (grid.empty() || grid[0].empty())
           return 0;
        
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        // 1. color the edge
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1)
              dfs(grid, i, 0);
            
            if (grid[i][n-1] == 1)
              dfs(grid, i, n-1);
        }

        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 1)
              dfs(grid, 0, j);
            
            if (grid[m-1][j] == 1)
              dfs(grid, m-1, j);
        }

        // 2. count island
        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
             if (grid[i][j] == 1)
             {
                //cnt += dfs(grid, i, j);
                cnt++;
             }
           }
        }

        return cnt;
    }

    int dfs(vector<vector<int>>& grid, int i, int j)
    {
       int m = grid.size();
       int n = grid[0].size();

       if (i < 0 || i >= m || j < 0 || j >= n)
         return 0;
       
       if (grid[i][j] != 1)
         return 0;
       
       int cnt = 1;
       grid[i][j] = 0;

       cnt += dfs(grid, i+1, j);
       cnt += dfs(grid, i-1, j);
       cnt += dfs(grid, i, j+1);
       cnt += dfs(grid, i, j-1);

       return cnt;
    }
};