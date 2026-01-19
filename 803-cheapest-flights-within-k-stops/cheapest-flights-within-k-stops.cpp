class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;

        vector<int> dist(n, INF);

        dist[src] = 0;

        for (int step = 0; step <= k; step++)
        {
          vector<int> prev = dist;
          for (auto& e: flights)
          {
             int u = e[0];
             int v = e[1];
             int w = e[2];

             if (prev[u] == INF)
               continue;
            
             dist[v] = min(dist[v], prev[u] + w);
          }
        }

        return dist[dst] == INF ? -1 :  dist[dst];
    }
};