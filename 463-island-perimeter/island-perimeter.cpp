class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int m = grid.size();
        if (m <= 0)
          return 0;
        int n = grid[0].size();
        if (n <= 0)
          return 0;
        
        // 4 * blocks - 2 * adj blocks; 
        int perim = 0;
        

        //避免算重
        //对当前格子 (i, j)：
        //上 (i-1, j)
        //→ 已经访问过

        //左 (i, j-1)
        //→ 已经访问过

        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (grid[i][j] == 1)
              {
                 perim += 4;

                 if (i > 0 && grid[i-1][j] == 1)
                   perim -=2;

                 if (j > 0 && grid[i][j-1] == 1)
                   perim -=2;
              }
           }
        }

        return perim;
    }
};