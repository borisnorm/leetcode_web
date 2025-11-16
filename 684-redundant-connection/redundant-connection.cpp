class Solution {

    vector<int> parent;
    vector<int> rank;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        if (edges.empty())
          return {};

        int n = edges.size();
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        for (int i = 0 ; i <= n; i++)
          parent[i] = i;

        vector<int> res;
        for (auto& e: edges)
        {
           int u = e[0];
           int v = e[1];

           if (!unite(u, v))
             return e;
        }

        return res;
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