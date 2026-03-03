class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        if (grid.empty() || grid[0].empty())
          return 0;

        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;
        for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
            {
               int area = dfs(grid, i, j);
                maxArea = max(maxArea, area); 
            }  

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || i < 0 || j >= n || j < 0)
          return 0;

        if (grid[i][j] != 1)
          return 0;

        grid[i][j] = 0;
       
        // area 是当前 i, j 的 面积, 算是初始化
        int area = 1;

        area += dfs(grid, i-1, j);
        area += dfs(grid, i+1, j);
        area += dfs(grid, i, j+1);
        area += dfs(grid, i, j-1);

        return area;
    }
    
};