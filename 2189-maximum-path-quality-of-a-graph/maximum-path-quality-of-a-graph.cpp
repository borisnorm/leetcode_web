class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();

        vector<vector<pair<int, int>>> graph(n);

        for (auto e: edges)
        {
           int u = e[0];
           int v = e[1];
           int time = e[2];

           graph[u].push_back({v, time});
           graph[v].push_back({u, time});
        }

        vector<int> visitCnt(n, 0);
        int maxQuality = 0;

        dfs(0, 0, 0, values, graph, visitCnt, maxTime, maxQuality);

        return maxQuality;
    }

    void dfs(int node, int curT, int curQ, vector<int>& values, 
            vector<vector<pair<int, int>>>& graph, 
            vector<int>& visitCnt, int maxT, int& maxQ)
         {
            if (visitCnt[node] == 0)
            {
               curQ += values[node];
            }
            visitCnt[node]++;

            if (node == 0)
              maxQ = max(maxQ, curQ);
            
            for (auto& [nei, travelT]: graph[node])
            {
                int newT = curT + travelT;
                if (newT <= maxT)
                {
                    dfs(nei, newT, curQ, values, graph, visitCnt, maxT, maxQ);
                }
            }

            visitCnt[node]--;
         }
};