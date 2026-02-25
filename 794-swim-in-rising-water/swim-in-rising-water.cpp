class Solution {
public:

    vector<int> parent;
    vector<int> rank;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // 把每个格子的 (高度, r, c) 存起来，按高度排序
        vector<tuple<int,int,int>> cells;
        for (int r = 0; r < n; r++)
           for (int c = 0; c < n; c++)
               cells.push_back({grid[r][c], r, c});
        sort(cells.begin(), cells.end()); // 按高度从小到大

        vector<vector<bool>> unlocked(n, vector<bool>(n, false)); // 标记已解锁
        
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        parent.assign(n * n, 0);
        for (int i = 0; i < n * n; i++)
          parent[i] = i;
        
        rank.assign(n * n, 0);
        
        for (auto& [t, x, y] : cells) 
        {
          unlocked[x][y] = true; // 解锁当前格子

          // 与四邻已解锁的格子合并
          for (auto& dir : dirs) 
          {
              int nx = x + dir.first;
              int ny = y + dir.second;


              if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

              if (!unlocked[nx][ny])
                continue;

              //if (nr >= 0 && nr < n && nc >= 0 && nc < n && unlocked[nr][nc])
              //  unite(r * n + c, nr * n + nc); // 二维坐标映射到一维

                unite(x * n + y, nx * n + ny);
          }

          // 检查起点终点是否连通
         if (connected(0, (n-1) * n + (n-1))) 
           return t;
        }

         return n * n - 1;
    }

    bool connected(int a, int b) 
    {
      return find(a) == find(b);
    }

    int find(int x)
    {
        if (parent[x] != x)
          parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int x, int y)
    {
       int rx = find(x);
       int ry = find(y);

       if (rx == ry)
         return false;
    
       if (rank[rx] > rank[ry])
       {
          // 把 小树 并入大树, 应该把 小树 的 parent 设为 大树的 parent
          parent[ry] = rx;
       }
       else if (rank[rx] < rank[ry])
       {
          //  ry 是大树,  小树的parent 应该是 大树
          parent[rx] = ry;
       }
       else
       {
          parent[rx] = ry;
          rank[ry]++;
       }

       return true;
    }
};
/*
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

*/