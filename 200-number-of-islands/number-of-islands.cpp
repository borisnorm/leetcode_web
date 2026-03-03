
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
          return 0;
        
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (grid[i][j] == '1' && !visited[i][j])
              {
                 bfs(grid, i, j, visited);
                 cnt++;
              }
           }
        }

        return cnt;
    }

    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited)
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        visited[i][j] = true;
        grid[i][j] = '0';

        while (!q.empty())
        {
           auto [x, y] = q.front();
           q.pop();

           for (auto dir : dirs)
           {
             int nx = x + dir.first;
             int ny = y + dir.second;

             if (nx < 0 || nx >= m || ny < 0 || ny >= n)
               continue;
            
             if (grid[nx][ny] != '1' || visited[nx][ny])
               continue;
            
              grid[nx][ny] = '0';
              visited[nx][ny] = true;

              q.push({nx, ny});
           }
        }
    }
};

/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
          return 0;
        
        // 时间 O(m × n) — 每个格子最多访问一次
        // 空间 O(min(m,n)) — BFS 队列最坏情况（蛇形岛屿）
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }

    int bfs(vector<vector<char>>& grid, int i, int j) {
        if (grid.empty() || grid[0].empty())
          return 0;
        
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> dirs = {
                {-1, 0},
            {0, -1},  {0, 1},
                {1, 0}
        };

        queue<pair<int, int>> q;
        q.push({i, j});

        //初始化染色很重要,不能少
        grid[i][j] = '0';

        int cnt = 0;
        while(!q.empty())
        {
            int q_sz = q.size();
            // 可以不使用这个 for 循环的
            //for (int i = 0; i < q_sz; i++)
            {
                auto [x, y] = q.front();
                q.pop();

                for(auto& d: dirs)
                {
                   int nx = x + d.first;
                   int ny = y + d.second;

                   if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                     continue;

                   if (grid[nx][ny] == '1')
                   {
                      grid[nx][ny] = '0';
                      q.push({nx, ny});
                   }
                    
                }
            }
        }

        return cnt;
    }


    // 时间复杂度 O(m x n)
    // 空间复杂度 O(m x n) at worst case
    int numIslands2(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
          return 0;

        int n_row = grid.size();
        int n_col = grid[0].size();

        int cnt = 0;

        for (int i = 0; i < n_row; i++)
          for (int j = 0; j < n_col; j++)
          {
            if (grid[i][j]=='1')
            {
                cnt++;
                dfs(grid, i, j);
            }
          }

        return cnt;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    { 
        //if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) 
        //  return;
        int n_row = grid.size();
        if (i < 0 || i >= n_row)
          return;

        int n_col = grid[0].size();
        if (j < 0 || j >= n_col)
          return;
        

        if (grid[i][j]=='0')
          return;

        grid[i][j] = '0';

        dfs(grid, i-1, j);
        dfs(grid, i+1, j);

        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};

*/