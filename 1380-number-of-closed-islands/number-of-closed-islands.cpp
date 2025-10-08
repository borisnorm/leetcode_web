class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.size() <=0 || grid[0].size() <=0)
          return 0;
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for (int i=0; i < m; i++)
        {
           dfs(grid, i, 0);
           dfs(grid, i, n-1);
        }

        for (int j=0; j < n; j++)
        {
           dfs(grid, 0, j);
           dfs(grid, m-1, j);
        }
        
        for (int i= 0; i < m; i++)
          for (int j= 0; j< n; j++)
          {
             if (grid[i][j]==1) 
               continue;
             cnt++;
             dfs(grid, i, j);
          } 
        
        return cnt;
    }

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i <0 || j < 0 || i >=m || j>= n)
          return;

        if (grid[i][j] == 1)
          return;

        grid[i][j] = 1;

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};