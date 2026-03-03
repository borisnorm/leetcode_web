class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
          return 0;

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.size();
        int n = grid[0].size();
        int perim = 0;
        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (grid[i][j] == 0)
                 continue;

              perim += 4;

              for (auto dir: dirs)
              {
                 int nx = i + dir.first;
                 int ny = j + dir.second;

                 if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                   continue;
                 
                 if (grid[nx][ny] == 1)
                   perim--;
              }

           }
        }

        return perim;
    }
};
/*
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        if (grid.empty() || grid[0].empty())
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

                 //   每个格子指计算 向上 与 向左的 cell == 1 的格子
                 //   cell 1 不会计算 与 cell 2 的交汇边
                 //   cell 2 会计算 与 cell 1 的交汇处
                 //   perim - 2 减的是自己的边, 与 上面的边
                 //   ____________
                 //   |           |
                 //   |     1     |
                 //   |           |
                 //   |           |
                 //   |-----------|
                 //   |	   ^     |
                 //   |     |     |
                 //   |<--- |     | 
                 //   |     |     |
                 //   |     2     |
                 //   |___________|
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

*/