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
               int area = bfs(grid, i, j);
                maxArea = max(maxArea, area); 
            }  

        return maxArea;
    }

    int bfs(vector<vector<int>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        int area = 1;

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        grid[i][j] = 0;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (auto dir : dirs)
            {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                  continue;
                
                if (grid[nx][ny] != 1)
                  continue;

                area++;
                grid[nx][ny] = 0;
                q.push({nx, ny});
            }
        }

        return area;
        
    }
};


/*
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
               int area = bfs(grid, i, j);
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
*/