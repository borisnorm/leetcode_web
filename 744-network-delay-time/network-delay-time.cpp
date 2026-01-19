class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Dijistra
        //                 dist, node
        vector<vector<pair<int, int>>> graph(n+1);

        for (auto e : times)
        {
            int u = e[0];
            int v = e[1];
            int t = e[2];
            
            graph[u].push_back({v, t});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        dist[0] = 0;

        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
          auto [curCost, u] = pq.top();
          pq.pop();

          if (curCost > dist[u])
            continue;
          
          for (auto [v, cost] : graph[u])
          {
             if (dist[v] > curCost + cost)
             {
                dist[v] = curCost + cost;

                pq.push({dist[v], v});
             }
          }
        }

        int maxCost = 0;
        for (int i = 1; i <= n; i++)
        {
           if (dist[i] == INT_MAX)
             return -1;
            
           maxCost = max(maxCost, dist[i]);
        }

        return maxCost;

    }
};