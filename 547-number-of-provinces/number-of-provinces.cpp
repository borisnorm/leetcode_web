class Solution {
public:
    struct UnionFind{
      vector<int> parent;
      vector<int> rank;
      void init(int n)
      {
         parent.assign(n, 0);
         for (int i = 0; i < n; i++)
           parent[i] = i;
         rank.assign(n, 0);
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
         if (rank[rx] < rank[ry])
           parent[rx] = ry;
         else if (rank[rx] > rank[ry])
           parent[ry] = rx;
         else
         {
           parent[ry] = rx;
           rank[rx]++;
         }
         return true;
      }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf;
        uf.init(n);

        vector<bool> visited(n, false);
        int nProvince = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
               if (isConnected[i][j] == 1 && uf.unite(i, j))
               {
                  visited[j] = true;
                  nProvince--;
               }
            }
        }

        return nProvince;

    }
};

/*
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
          if (!visited[i])
          {
            q.push(i);
            visited[i] = true;

            provinces++;
            
            while (!q.empty())
            {
              int u = q.front();
              q.pop();
            
              //u 可能是任意城市，它的邻居可能在它左边（v < u）或右边（v > u）
              // 所以必须扫描 0 到 n-1 全部
              for (int v = 0; v < n; v++)
              {
                if (isConnected[u][v] == 1 && !visited[v])
                {
                  visited[v] = true;
                  q.push(v);
                }
              }
            }
          }
        }
        return provinces;
    }
};
*/