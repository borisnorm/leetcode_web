class Solution {
public:
    vector<pair<int, int>> dirs = 
    {           {-1, 0},
         {0, -1},      {0, 1},
                {1,  0} 
    };

    void wallsAndGates(vector<vector<int>>& rooms) {
        
        int m = rooms.size();
        int n = rooms[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
            if (rooms[i][j] == 0)
               q.push({i, j});

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (auto d: dirs)
            {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                  continue;
                
                if (rooms[nx][ny] == INT_MAX)
                { 
                   rooms[nx][ny] = rooms[x][y] + 1;
                   q.push({nx, ny});
                }
            }
        }
        return;
    }
};