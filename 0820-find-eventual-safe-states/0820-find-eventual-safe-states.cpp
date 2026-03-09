class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
                
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> outDegree(n, 0);

        for (int i = 0; i < n; i++)
        {
           int u = i;
           for (int v: graph[u])
           {
              //ååå»ºè¾¹
              revGraph[v].push_back(u);
              outDegree[u]++;
           }
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (outDegree[i] == 0)
              q.push(i);
        }

        vector<bool> safe(n, false);

        while (!q.empty())
        {
          int u = q.front();
          q.pop();

          safe[u] = true;

          for (int v: revGraph[u])
          {
             outDegree[v]--;
             if (outDegree[v] == 0)
                q.push(v);
          }
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
           if (safe[i])
            res.push_back(i);
        }
        return res;
    }
};