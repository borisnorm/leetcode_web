class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m)
          return 0;

        int n = grid[0].size();
        if (!n)
          return 0;  

        queue<pair<int, int>> q; // 多源BFS 起点
        int nfresh = 0;

        for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
          {
             if (grid[i][j] == 2)
               q.push(make_pair(i,j));
             else if (grid[i][j] == 1)
               nfresh++;
          }

        if (nfresh == 0)
          return 0;

        int minutes = 0;   //返回的是分钟数
        int dirs[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty())
        {
           int q_size = q.size();
           bool infected = false;

           for (int k = 0; k < q_size; k++) 
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

                grid[nx][ny] = 2;
                
                nfresh--;

                infected = true;

                q.push(make_pair(nx, ny));
             }
           }    

           if (infected)
             minutes++;
        }

        return (nfresh == 0) ? minutes : -1;
    }
};