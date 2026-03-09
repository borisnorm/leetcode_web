class Solution
{
public:

    // DFS函数：遍历所有与 city 相连的城市
    void dfs(vector<vector<int>>& isConnected, int city, vector<bool>& visited)
    {
        int n = isConnected.size();                // 城市数量
        
        visited[city] = true;                      // 标记当前城市已访问
        
        // 遍历所有可能的邻居城市
        for (int neighbor = 0; neighbor < n; neighbor++)
        {
            // 如果两个城市相连 且 neighbor 未访问
            if (isConnected[city][neighbor] == 1 && !visited[neighbor])
            {
                dfs(isConnected, neighbor, visited); // 继续DFS
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();                // 城市数量
        
        vector<bool> visited(n, false);            // 访问数组
        
        int provinces = 0;                         // 省份数量
        
        // 遍历所有城市
        for (int i = 0; i < n; i++)
        {
            // 如果该城市没有被访问
            if (!visited[i])
            {
                dfs(isConnected, i, visited);      // DFS遍历整个连通块
                
                provinces++;                       // 发现一个新的province
            }
        }
        
        return provinces;                          // 返回省份数量
    }
};
/*
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
*/

/*
// Time: O(n^2)
// Space: O(n)
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