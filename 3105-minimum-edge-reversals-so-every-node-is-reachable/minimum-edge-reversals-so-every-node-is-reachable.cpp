class Solution {
public:
    vector<int> res;
    // u, w(reverse time) 
    vector<vector<pair<int, int>>> graph;

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        
         graph.resize(n);
         res.resize(n);

         for (auto edge: edges)
         {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back({v, 0});
            graph[v].push_back({u, 1});

         }

        
        dfs1(0, -1);
        dfs2(0, -1);

        return res;
    }

    void dfs1(int u, int parent)
    {
       for (auto& [v, w]: graph[u])
       {
          if (v == parent)
            continue;
        
          res[0] += w;
          dfs1(v, u);
       }
    }

    void dfs2(int u, int parent)
    {
        for (auto& [v, w]: graph[u])
        {
            if (v == parent)
              continue;

           // 计算的翻转的数量 如果是顺路,就必须要翻转, 所以是 +1
           res[v] += res[u] + (w == 0 ? 1: -1);
           dfs2(v, u);
        }
    }
};