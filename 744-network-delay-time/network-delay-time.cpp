class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Dijistra       dist, node
        vector<vector<pair<int, int>>> graph(n+1);

        for (auto e : times)
        {
            int u = e[0];
            int v = e[1];
            int t = e[2];
            
            graph[u].push_back({v, t});
        }

        vector<int> distCost(n+1, INT_MAX);
        distCost[k] = 0;   // k 到 k 的距离为 0
        //dist[0] = 0;   // 0 不使用

        //             (distanceCost , node)
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<>> pq;
        // k 是起点
        pq.push({0, k});

        while (!pq.empty())
        {
          auto [cur_dist_cost, u] = pq.top();
          pq.pop();

          // skip 过时的 curCost 
          if (cur_dist_cost > distCost[u])
            continue;
          
          for (auto [v, cost] : graph[u])
          {  
             // min

             // dist[u] = 从起点 k 到 u 所花的时间
             // w  = 从 u 到 v 这条边所花的时间
             // dist[u] + w = 从起点 k 经过 u 再到 v 所花的总时间
             // 在这道题里，距离 = 时间，是同一个东西。

             if (distCost[v] > cur_dist_cost + cost)
             {
                distCost[v] = cur_dist_cost + cost;
                pq.push({distCost[v], v});             
             }
          }
        }

        //所有节点都收到信号的时刻 = 最后一个节点收到的时刻 = max(dist[])            
        int maxCost = 0;
        for (int i = 1; i <= n; i++)
        {
           //节点 不连通
           if (distCost[i] == INT_MAX)
             return -1;
            
           maxCost = max(maxCost, distCost[i]);
        }
        return maxCost;
    }
};