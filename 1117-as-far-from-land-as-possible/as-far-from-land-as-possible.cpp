class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        

        //min
        //max

        int m = grid.size();
        int n = grid[0].size();

        // step , i, j
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < m; i++)
        {
          for (int j = 0; j < n; j++)
          {
             if (grid[i][j] == 1)
             {
                q.push({0, i, j});
             }
          }
        }

        if (q.empty() || q.size() == n * n)
          return -1;

        int maxDist = 0;

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty())
        {
           auto [step, x, y] = q.front();
           q.pop();
          
           maxDist = max(maxDist, step);

           for (auto dir : dirs)
           {
              int nx = x + dir.first;
              int ny = y + dir.second;

              if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
              
              if (grid[nx][ny] != 0)
                continue;

              grid[nx][ny] = 1;

              q.push({step + 1, nx, ny});
           }
        }

        return maxDist == 0 ? -1 : maxDist;
    }
};