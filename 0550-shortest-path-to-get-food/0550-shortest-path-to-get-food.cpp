class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
               if (grid[i][j] == '*')
               {
                  grid[i][j] = 'X';
                  q.push({i,j});
               }
            }
        }

        vector<pair<int, int>> dirs = {
                 {-1, 0},
            {0, -1},  {0, 1},
                 {1, 0}
        }; 

        int step = 0;
        while (!q.empty())
        {
           int q_sz = q.size();

           for (int i = 0; i < q_sz; i++)
           {
             auto [x, y] = q.front();
             q.pop();

             for (auto d : dirs)
             {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                  continue;
              
                if (grid[nx][ny] == 'X')
                  continue;

                if (grid[nx][ny] == '#')
                  return step + 1; 

                if (grid[nx][ny] == 'O')
                {
                  grid[nx][ny] = 'X';
                  q.push({nx, ny});
                }
             }
           }

           step++;
        }

        return -1;
    }
};