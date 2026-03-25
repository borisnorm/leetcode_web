class Solution
{
public:
    vector<int> par, rnk;

    // 路径压缩
    int find(int x)
    {
        if (par[x] != x)
            par[x] = find(par[x]);
        return par[x];
    }

    // 按秩合并
    void unite(int a, int b)
    {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells)
    {
        int n = row * col;
        int src = n, sink = n + 1; // 虚拟源点和汇点

        // 初始化 UF，n+2 个节点
        par.resize(n + 2);
        rnk.resize(n + 2, 0);
        for (int i = 0; i < n + 2; i++)
            par[i] = i;

        // 初始全部是水，grid[i]=1表示水，0表示陆地
        vector<int> grid(n, 1);

        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        // 从最后一天倒着加陆地
        for (int d = (int)cells.size() - 1; d >= 0; d--)
        {
            int x = cells[d][0] - 1;
            int y = cells[d][1] - 1;
            int id = x * col + y;

            grid[id] = 0; // 变回陆地

            // 和四周陆地 union
            for (auto& dir : dirs)
            {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx < 0 || nx >= row || ny < 0 || ny >= col)
                    continue;
                int nid = nx * col + ny;
                if (grid[nid] == 0) // 邻居是陆地才 union
                    unite(id, nid);
            }

            // 第一行连 src，最后一行连 sink
            if (x == 0)       unite(id, src);
            if (x == row - 1) unite(id, sink);

            // src 和 sink 连通了，当前天就是答案
            if (find(src) == find(sink))
                return d; // d 是 0-indexed，正好对应第 d+1 天？
                           // 不对！cells[d] 是第 d+1 天泡水的格子
                           // 倒着加回来后第 d 天陆地 = cells[0..d-1] 是水
                           // 所以答案就是 d（即第 d 天是最后可通过的天）
        }

        return 0;
    }
};
/*
class Solution {
public:

    bool canCross(int row, int col, vector<vector<int>>& cells, int mid)
    {
       // 0 - land
       vector<vector<int>> grid(row, vector<int>(col, 0));
       for (int i = 0; i < mid; i++)
       {
          int x = cells[i][0] - 1;
          int y = cells[i][1] - 1;
          grid[x][y] = 1;
       }

       queue<pair<int, int>> q;

       for (int j = 0; j < col; j++)
       {
          if (grid[0][j] == 0)
          {
             q.push({0, j});
          }
       }

       vector<pair<int, int>> dirs = {{0, 1},  {0, -1},  {1, 0},  {-1, 0}};
       while (!q.empty())
       {
          auto [x, y] = q.front();
          q.pop();

          if (x == row -1)
            return true;

          for (auto dir : dirs)
          {
             int nx = x + dir.first;
             int ny = y + dir.second;

             if (nx < 0 || nx >= row || ny < 0 || ny >= col)
               continue;
              
             if (grid[nx][ny] != 0)
                continue;

              grid[nx][ny] = 1;
              q.push({nx, ny});
          }
          
       }

       return false;
    }


    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 1;
        int hi = cells.size();  // cells 这里表示了 天数
        int lastDay = 0;

        while (lo <= hi)
        {
           int mid = lo + (hi-lo)/2;
            
           if (canCross(row, col, cells, mid))
           {
              lastDay = mid;
              lo =  mid + 1;
           }
           else
           {
              hi =  mid - 1;
           }
        }

        return lastDay;

    }
};

*/