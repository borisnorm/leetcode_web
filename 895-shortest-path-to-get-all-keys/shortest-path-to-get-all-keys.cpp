class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        // lower is key
        // upper is lock
        int m = grid.size();
        int n = grid[0].size();
        int sr = 0;
        int sc = 0;
        int kCnt = 0;  //所有 key 的总数

        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              // '@' is the staring point
              if (grid[i][j] == '@')
              {
                 sr = i;
                 sc = j;
              }

              if (islower(grid[i][j]))
                kCnt++;  // a - f 是钥匙
           }
        }
        
        //  3把锁, 1<< 3 = 1000, -1 后就是 0111
        //  正好是我们要的mask 
        int full = (1 << kCnt) - 1;

        //因为 1 << k 是状态的总数量, 
        //000 = 0
        //001 = 1
        //010 = 2
        //011 = 3
        //100 = 4
        //101 = 5
        //110 = 6
        //111 = 7  ← 这就是 full = (1<<3)-1 = 7
        // 总共 8种状态 = 1 << 3
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1 << kCnt, false)));
    
        queue<tuple<int, int, int>> q;
        q.push({sr, sc, 0});
        vis[sr][sc][0] = true;

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int step = 0;
        
        while (!q.empty())
        {
           int q_sz = q.size();
           for (int i = 0; i < q_sz; i++)
           {
              auto [x, y, keys_status] = q.front();
              q.pop();

              if (keys_status == full)
                return step;
              
              for (auto& d: dirs)
              {
                 int nx = x + d[0];
                 int ny = y + d[1];
                 if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                   continue;
                 char ch = grid[nx][ny];
                 // '#' is a wall
                 if (ch == '#')
                   continue;

                 int nkeys_status = keys_status;

                 if (isupper(ch))
                 {
                    //ch - 'A' 表示：这把锁对应第几个bit位
                    // 'A' - 'A' = 0  → bit 0
                    // 'B' - 'A' = 1  → bit 1
                    // 'C' - 'A' = 2  → bit 2
                    if (!(keys_status & (1 << (ch - 'A'))))
                      continue;
                 }
                 
                 if (islower(ch))
                   nkeys_status |= (1 << (ch - 'a'));
                
                 if (!vis[nx][ny][nkeys_status])
                 {
            
                    vis[nx][ny][nkeys_status] = true;
                    q.push({nx, ny, nkeys_status});
                 }

              }
           }

           step++;
        }
        return -1;
    }
};