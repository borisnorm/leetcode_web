class Solution {
public:

    struct UnionFind{
      vector<int> parent;
      vector<int> rank;

      UnionFind(int n){
         parent.assign(n, 0);
         iota(parent.begin(), parent.end(), 0);
         rank.assign(n, 0);
      }

      int find(int x)
      {
         if (parent[x] != x)
           parent[x] = find(parent[x]);
          
         return parent[x];
      }

      void unite(int x, int y)
      {
        int rx = find(x);
        int ry = find(y);

        if (rx == ry)
          return;
        
        // rx 变成大树
        if (rank[rx] < rank[ry])
         swap(parent[rx], parent[ry]);
        
        parent[ry] = rx;
        rank[rx] += rank[ry];
        
      }
    };
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UnionFind uf(c+1);
        vector<int> status(c+1, 1);
        for(auto connection: connections)
        {
           int u = connection[0];
           int v = connection[1];
           uf.unite(u, v);
        }

        int n = queries.size();
        vector<int> res;
        vector<set<int>> group(c+1);

        for (int i = 1; i <= c; i++)
        {
           int root = uf.find(i);
           group[root].insert(i);
        }

        for (auto query: queries)
        {
            int type = query[0];
            int station = query[1];

            int root = uf.find(station);

            if (type == 1)
            {
               if (status[station])
               {
                 res.push_back(station);
               }
               else if (group[root].empty())
               {
                 res.push_back(-1);
               }
               else
               {
                 int lowest_station = *group[root].begin();
                 res.push_back(lowest_station);
               }
            }
            else if (type == 2)
            {
               if (status[station])
               {
                  status[station] = 0;
                  group[root].erase(station);
               }
            }
        }

        return res;
    }
};