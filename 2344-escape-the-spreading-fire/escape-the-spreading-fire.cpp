class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int INF = 1e9;

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1},  {1, 0}, {-1, 0}};
        vector<vector<int>> fireT(m, vector<int>(n, INF));
        queue<array<int, 2>> q;

        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (grid[i][j] == 1)
              {
                 fireT[i][j] = 0;
                 q.push({i, j});
              }
           }
        } 

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
              
              //墙
              if (grid[nx][ny] == 2) 
                continue;

              if (fireT[nx][ny] != INF)
                continue; //已访问'
              
              fireT[nx][ny] = fireT[x][y] + 1;
              q.push({nx, ny});
           }
        }   

        auto canReach = [&](int t) -> bool
        {
           if (t >= fireT[0][0])
             return false;
           
           vector<vector<int>> dist(m, vector<int>(n, INF));
           dist[0][0] = t; //人在起点的时刻

           queue<array<int, 2>> pq;
           pq.push({0, 0});

           while(!pq.empty())
           {
              auto [x,y] = pq.front();
              pq.pop();

              for (auto dir: dirs)
              {
                 int nx = x + dir.first;
                 int ny = y + dir.second;

                 if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                   continue;
                 
                 if (grid[nx][ny] == 2)
                   continue;
                  
                  if (dist[nx][ny] != INF)
                    continue; 

                  int arrT = dist[x][y] + 1;

                  if (nx == m-1 && ny == n-1)
                  {
                     if (arrT <= fireT[nx][ny])
                       return true;
                     else
                       continue;
                  }

                  if (arrT >= fireT[nx][ny])
                    continue;
                  
                  dist[nx][ny] = arrT;
                  pq.push({nx,ny});
              }
           }

           return false;
        };

        int lo = 0; 
        int hi = m * n;
        if (!canReach(0))
          return -1;

        while (lo < hi)
        {
          int mid = lo + (hi - lo + 1) / 2;
          if (canReach(mid))
            lo = mid;
          else
            hi = mid - 1;
        }

        return (lo == m * n) ? 1e9 : lo;
    }
};