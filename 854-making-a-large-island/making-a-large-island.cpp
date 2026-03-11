class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> area;
        int id = 2;
        // Step 1: 遍历所有格子，给每个岛屿染色并记录面积
        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (grid[i][j] == 1)
              {
                 area[id] = dfs(grid, i, j, id);
                 id++;
              }
           }
        }

        // Step 2: 初始答案 — 处理全是 1 的情况（没有 0 可以翻转）
        int maxArea = 0;
        for (auto [id, gridArea]: area)
          maxArea = max(maxArea, gridArea);

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Step 3: 枚举每个 0，尝试翻转
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < n; j++)
          {
            if (grid[i][j] != 0)
              continue;
             unordered_set<int> seen;
            int total = 1; // reverse itselft;
            
            for (auto dir: dirs)
            {
               int nI = i + dir.first;
               int nJ = j + dir.second;
               
               if (nI < 0 || nI >= n || nJ < 0 || nJ >= n)
                 continue;
                
               int nId = grid[nI][nJ];
               if (nId >= 2 && !seen.count(nId))
               { 
                  seen.insert(nId);
                  total += area[nId];
               }
            }
            
            maxArea = max(maxArea, total);
          }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int id)
    {
       int n = grid.size();
       if (i < 0 || i >= n || j < 0 || j >= n)
         return 0;

       if (grid[i][j] != 1)
         return 0;

       grid[i][j] = id;
      
       int area = 1;

       area += dfs(grid, i+1, j, id);
       area += dfs(grid, i-1, j, id);
       area += dfs(grid, i, j+1, id);
       area += dfs(grid, i, j-1, id);

      return area;
    }
};