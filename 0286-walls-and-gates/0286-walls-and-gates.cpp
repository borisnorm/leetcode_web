class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty())
          return;

        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (rooms[i][j] == 0)
              {
                 q.push({i, j});
              }
           }
        }

        vector<pair<int, int>> dirs = {{0,1}, {0, -1}, {1, 0},  {-1, 0}};
        int dist = 0;
        
        while(!q.empty())
        {
           auto [x, y] = q.front();
           q.pop();

           for(auto& dir: dirs)
           {
              int nx = x + dir.first;
              int ny = y + dir.second;

              if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            
              if (rooms[nx][ny] != INT_MAX)
                continue;
            
              rooms[nx][ny] = rooms[x][y] + 1;
              q.push({nx, ny});
           }
        }
    }

};