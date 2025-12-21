class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        // 0, 1, -1
        vector<int> color(n, 0);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
           if (color[i])
             continue;

           q.push(i);
           color[i] = 1;

           while(!q.empty())
           {
              int u = q.front();
              q.pop();

              for (int v : graph[u])
              {
                if (color[v] == 0)
                {
                   color[v] = -color[u];
                   q.push(v);
                }
                else if (color[v] == color[u])
                  return false;
              }
           }

        }

        return true;
    }
};