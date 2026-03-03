class Solution {
public:

    int cnt;
    vector<int> parent;
    vector<int> rank;

    void uf_init(int m, int n, vector<vector<int>>& positions)
    {
        cnt = positions.size();

        parent.assign(m * n, 0);
        rank.assign(m * n, 0);

        for (int i = 0; i < cnt; i++)
        {
            int x = positions[i][0];
            int y = positions[i][1];

           
            int id = x * n + y;
            parent[id] = id;
            // è¿ä¸ªåå§å, æ¯éè¯¯ç
            //è¿éç i æ¯ positions çä¸æ 
            //ä½åé¢ unite(id, nid) ä¼ è¿å»ç id/nid æ¯æ ¼å­ç 1D ç¼å· = x*n+yï¼èå´æ¯ [0, m*n-1]
            //parent[i] = i;
        }
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
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
          vector<vector<int>> grid(m, vector<int>(n, 0));
          
          uf_init(m, n, positions);

          vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

          int nIsland = 0;
          vector<int> res(cnt);

          for (int i = 0; i < cnt; i++)
          {
            int x = positions[i][0];
            int y = positions[i][1];

            int id = x * n + y;

            if (grid[x][y] == 1)
            {
               res[i] = nIsland;
               continue;
            }

            grid[x][y] = 1;
            nIsland++;

            int united_cnt = 0;
            for (auto dir: dirs)
            {
               int nx = x + dir.first;
               int ny = y + dir.second;

               if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                 continue;
               
               if (grid[nx][ny] != 1)
                 continue;

               int nid = nx * n + ny;

               if (unite(id, nid))
               {
                 nIsland--;
               }
            }

            res[i] = nIsland;
          }
          
       return res;
    }
};