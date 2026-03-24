class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // 0 - empty
        // 1 - guard
        // 2 - wall
        // 3 = guarded
        for (auto wall: walls)
        {
          int x = wall[0];
          int y = wall[1];
          grid[x][y] = 2;
        }

        for (auto guard: guards)
        {
          int x = guard[0];
          int y = guard[1]; 
          grid[x][y] = 1;
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0},  {-1, 0}};
        for (auto guard: guards)
        {
          int x = guard[0];
          int y = guard[1]; 

          for (auto dir: dirs)
          {
              int nx = x + dir.first;
              int ny = y + dir.second;

              if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                 continue;

              if (grid[nx][ny] == 1 || grid[nx][ny] == 2)
                continue;

              while (0 <= nx && nx < m && 0 <= ny && ny < n && 
                     (grid[nx][ny] == 0 || grid[nx][ny] == 3))
              {
                 grid[nx][ny] = 3;
                 nx += dir.first;
                 ny += dir.second;
              }
          } 
        } 

        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (grid[i][j] == 0)
                cnt++;
           }
        }
        return cnt;
    }
};
/*
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // 0 - empty
        // 1 - guard
        // 2 - wall
        // 3 = guarded
        for (auto wall: walls)
        {
          int x = wall[0];
          int y = wall[1];
          grid[x][y] = 2;
        }

        queue<pair<int, int>> q;

        for (auto guard: guards)
        {
          int x = guard[0];
          int y = guard[1];
          grid[x][y] = 1;
          q.push({x, y});
        } 
        
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0},  {-1, 0}};
        while(!q.empty())
        {
           auto [x, y] = q.front();
           q.pop();

           for (auto dir: dirs)
           {
              int nx = x + dir.first;
              int ny = y + dir.second;
              if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                 continue;

              if (grid[nx][ny] == 1 || grid[nx][ny] == 2)
                continue;

              while (0 <= nx && nx < m && 0 <= ny && ny < n && 
                     (grid[nx][ny] == 0 || grid[nx][ny] == 3))
              {
                 grid[nx][ny] = 3;
                 nx += dir.first;
                 ny += dir.second;
              }

           }
        }
      
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (grid[i][j] == 0)
                cnt++;
           }
        }
        return cnt;
    }
};

*/