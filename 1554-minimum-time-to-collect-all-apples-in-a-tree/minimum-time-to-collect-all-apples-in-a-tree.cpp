class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
  
        // edges == n -1
        for (auto edge: edges)
        {
           int u = edge[0];
           int v = edge[1];

           graph[u].push_back(v);
           graph[v].push_back(u);
        }

      
      return  dfs(graph, -1, 0, hasApple);
    }

    int dfs(vector<vector<int>>& graph, int par, int cur, vector<bool>& hasApple)
    {
       int cost = 0;
       for (int nxt: graph[cur])
       {
          // 不回走 parent
          if (nxt == par)
            continue;

          int sub = dfs(graph, cur, nxt, hasApple);

          // sub 有 cost 或是  next 就有 apple
          if (sub > 0 || hasApple[nxt])
          {
            cost += sub + 2;
          }
       }

       return cost;
    }
};