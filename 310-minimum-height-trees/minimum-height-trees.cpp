class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        //edges to adju
        // 0
        // 1
        // 2
        // 3 
        if (n == 1)
          return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
           int u = edges[i][0];
           int v = edges[i][1];

           adj[u].push_back(v);
           adj[v].push_back(u);
           degree[u]++;
           degree[v]++; 
        }

        queue<int> q;
        for (int i = 0; i < n; i++){
            if (degree[i] == 1)
               q.push(i);
        }

        int remaining = n;

        while(remaining > 2)
        {
           int q_sz = q.size();
           remaining -= q_sz;
           for (int i = 0; i < q_sz; i++)
           {
              int v = q.front();
              q.pop();

              for (int nei: adj[v])
              {
                  degree[nei]--;
                  if (degree[nei] == 1)
                     q.push(nei);
              }
           }
        }

        vector<int> res;
        while(!q.empty())
        {
           res.push_back(q.front());
           q.pop();
        }

        return res;

    }
};