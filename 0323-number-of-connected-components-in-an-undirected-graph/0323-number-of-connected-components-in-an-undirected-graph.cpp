class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x)
    {
       if (parent[x] != x)
         return find(parent[x]);
       
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
    int countComponents(int n, vector<vector<int>>& edges) {
        
        if (edges.empty())
          return n;

        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++)
          parent[i] = i;
        
        rank.assign(n, 0);

        int components = n;
        for (auto& edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
             
            if (unite(u, v))
              components--;
        }

        return components;
    }
};