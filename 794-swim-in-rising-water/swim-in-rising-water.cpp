class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0], 0, 0});

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1},  {1, 0}, {-1, 0}};

        while (!pq.empty())
        {
           auto [cost, x, y] = pq.top();
           pq.pop();

           if (x == n - 1 && y == n - 1)
             return cost;

           if (cost > dist[x][y])
             continue;
           
           for (auto dir: dirs)
           {
              int nx = x + dir.first;
              int ny = y + dir.second;

              if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
              
              int nCost = max(cost, grid[nx][ny]);

              if (nCost < dist[nx][ny])
              {
                 dist[nx][ny] = nCost;
                 pq.push({nCost, nx, ny});
              }
           }
        }
        return dist[n-1][n-1];
    }
};