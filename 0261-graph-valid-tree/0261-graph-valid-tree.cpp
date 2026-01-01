class Solution {
public:

    int find(vector<int>& parent, int x)
    {
        if (parent[x] != x)
          return find(parent, parent[x]);
         
        return parent[x];
    }

    bool unite(vector<int>& parent, vector<int>& rank, int x, int y)
    {
        int rx = find(parent, x);
        int ry = find(parent, y);

        if (rx == ry)
          return false;
  
        if (rank[rx] < rank[ry])
        {
            parent[rx] = ry;
        }
        else if (parent[rx] > parent[ry])
        {
            parent[ry] = rx;
        }
        else
        {
            parent[ry] = rx;
            rank[rx]++;
        }

        return true;

    }
 
    bool validTree(int n, vector<vector<int>>& edges) {
          // condition 1:  num of edges is nodes - 1;
          if (edges.size() != n -1)
            return false;
        
          vector<int> parent(n);
          vector<int> rank(n, 0);
          for (int i=0; i < n; i++)
            parent[i] = i;

          // condition 2: no cycle
          for (auto& edge: edges)
          {
             int u = edge[0];
             int v = edge[1];
             if (!unite(parent, rank, u, v))
               return false;
          }

          return true;
    }
};