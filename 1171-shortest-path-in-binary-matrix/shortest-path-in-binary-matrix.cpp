class Solution {
public:

    vector<pair<int, int>> dirs = {
       {-1,-1} , {-1, 0},  {-1, 1},
       {0, -1},            {0,  1},
       {1, -1},  {1, 0},   {1,  1} 
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        if (m == 0)
          return -1;
        int n = grid[0].size();
        if (n == 0)
          return -1;

        if (grid[0][0] == 1 || grid[m-1][n-1] == 1)
          return  -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int step = 1;
        while(!q.empty())
        {
          int q_sz = q.size();

          for (int i = 0; i < q_sz; i++)
          {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1)
            {
              return step;   
            }

            for (auto d: dirs)
            {
              int nx = x + d.first;
              int ny = y + d.second;

              if (nx >=m || nx < 0 || ny >= n || ny < 0)
                continue;

              if (grid[nx][ny] == 1)
                continue;

              q.push({nx, ny});

              grid[nx][ny] = 1;
            }
          }

          step++;

        }
          
        return -1;
    }
};