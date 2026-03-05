class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
          return 0;
        
        // 0 - empty
        // 1 - fresh orange
        // 2 - rotten 
        int m = grid.size();
        int n = grid[0].size();

        // each min, 2.rotten adjacent fresh become rotten
        // return min minutes to have all rotten oranges

        queue<pair<int, int>> q; // 多源BFS 起点
        int nfresh = 0;

        for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
          {
             if (grid[i][j] == 2)
               q.push({i, j});
             else if (grid[i][j] == 1)
               nfresh++;
          }

        if (nfresh == 0)
          return 0;

        int minutes = 0;   //返回的是分钟数
        int dirs[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty())
        {
           int q_sz = q.size();
           bool infected = false;

           for (int k = 0; k < q_sz; k++) 
           {
             pair<int, int>  cur = q.front();
             q.pop();
             int x = cur.first;
             int y = cur.second;

             for (int d = 0; d < 4; d++)
             {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];
                
                if (nx >= m || nx < 0 || ny >= n || ny < 0)
                  continue;
                
                if (grid[nx][ny] != 1)
                  continue;

                infected = true;

                grid[nx][ny] = 2;
                nfresh--;

                q.push({nx, ny});
             }
           }    

           if (infected)
             minutes++;
        }

        // 原来只有1个 rotten orange, 返回 minutes 0
        return (nfresh > 0) ? -1 : minutes;
    }
};