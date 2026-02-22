class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int m = heightMap.size();
        int n = heightMap[0].size();

         // 4 4 4
         // 4 1 4
         // 4 4 4 最小 size 也就是 3
        if (m < 3 || n < 3)
          return 0;

        // height, row, col
        using T = tuple<int, int, int>;

        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m-1 || j == 0 || j == n-1)
                {
                   pq.push({heightMap[i][j], i, j});
                   visited[i][j] = true;
                }
            }
        }

        int res = 0;
        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        while(!pq.empty())
        {
            auto [height, x, y] = pq.top();
            pq.pop();

            for (auto& [dx, dy]: dirs)
            {
               int nx = x + dx;
               int ny = y + dy;

               if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                 continue;
                
               if (visited[nx][ny])
                 continue;
               
               if (heightMap[nx][ny] < height)
                 res += (height - heightMap[nx][ny]);
              
               pq.push({max(height, heightMap[nx][ny]), nx, ny});

               visited[nx][ny] = true;
            }
        }

        return res;
    }
};