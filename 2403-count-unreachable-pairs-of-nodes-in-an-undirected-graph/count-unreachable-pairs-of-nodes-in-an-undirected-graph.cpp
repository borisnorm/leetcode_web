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

      UnionFind(int n)
      {
         init(n);
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

      bool isConnected(int x, int y)
      {
         return (find(x) == find(y)) ? true : false;
      }
    };
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);

        for (auto e: edges)
        {
           int u = e[0];
           int v = e[1];

           uf.unite(u, v);
        }

        vector<long long> sz(n, 0);
        // 统计 根 个频率
        for (int i = 0; i < n; i++)
        {
          int rootId = uf.find(i);
          sz[rootId]++;
        }

        long long cnt = 0;
        long long remain = n;
        for (int i = 0; i < n; i++)
        {
          //skip 非根节点
          if (sz[i] == 0)
            continue;
          
          remain -= sz[i];
          cnt += 1LL * sz[i] * remain;
        }
        return cnt;
    }
};