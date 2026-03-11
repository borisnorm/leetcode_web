class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
          int n = grid.size();
          
          bool found = false;
          queue<pair<int, int>> q;
          vector<vector<int>> visited(n, vector<int>(n, 0));
          //DFS - queue -> multiple BFS
          for (int i = 0; i < n && !found; i++)
          {
            for (int j = 0; j < n && !found; j++)
            {
               if (grid[i][j] == 1)
               {
                  dfs(grid, i, j, q, visited);
                  found = true;
               }
            }
          }

          //BFS
          int step = 0;
          vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
          while (!q.empty())
          {
            int q_sz = q.size();
            for (int i = 0 ; i < q_sz; i++)
            {
               auto [x, y] = q.front();
               q.pop();

               for (auto dir: dirs)
               {
                  int nx = x + dir.first;
                  int ny = y + dir.second;

                  if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                  
                  if (visited[nx][ny])
                    continue;
                  
                  if (grid[nx][ny] == 1)
                    return step;
                  
                  visited[nx][ny] = 1;
                  q.push({nx, ny});
               }
            }

            step++;
          }

          return step;
    }

    // not necessary for coloring
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q, vector<vector<int>>& visited)
    {
       int n = grid.size();

       if (i < 0 || i >= n || j < 0 || j >= n)
         return;
       
       if (grid[i][j] != 1)
         return;

       if (visited[i][j])
         return;
      
       q.push({i, j});
       visited[i][j] = 1;

       dfs(grid, i+1, j, q, visited);
       dfs(grid, i-1, j, q, visited);
       dfs(grid, i, j+1, q, visited);
       dfs(grid, i, j-1, q, visited);
    }
};