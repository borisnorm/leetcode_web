class Solution
{
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int m = mat.size();                         // 行数
        int n = mat[0].size();                      // 列数

        queue<pair<int,int>> q;                     // BFS 队列

        // Step1 初始化
        for(int i = 0; i < m; i++)                  // 遍历所有行
        {
            for(int j = 0; j < n; j++)              // 遍历所有列
            {
                if(mat[i][j] == 0)                  // 如果是0
                {
                    q.push({i,j});                  // 入队作为 BFS 起点
                }
                else
                {
                    mat[i][j] = INT_MAX;            // 1 标记为 INF（未访问）
                }
            }
        }

        // 四个方向
        int dirs[4][2] =
        {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        // Step2 BFS
        while(!q.empty())
        {
            auto [x,y] = q.front();                 // 取出队头
            q.pop();                                // 弹出

            for(auto &d : dirs)                     // 遍历四个方向
            {
                int nx = x + d[0];                  // 新坐标
                int ny = y + d[1];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;                       // 越界跳过

                // 如果找到更短路径
                if(mat[nx][ny] > mat[x][y] + 1)
                {
                    mat[nx][ny] = mat[x][y] + 1;    // 更新距离
                    q.push({nx,ny});                // 入队继续扩散
                }
            }
        }

        return mat;                                 // mat 已经变成 dist
    }
};
/*
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
          for (int j = 0; j < n; j++)
          {
            if (mat[i][j] == 0)
            {
                res[i][j] = 0;
                q.push({i, j});
            }
          }
        }
        
        vector<pair<int, int>> dirs = {{0, 1},  {0, -1},  {1, 0},  {-1, 0}};
        while (!q.empty())
        {
          auto [x, y] = q.front();
          q.pop();

          for (auto dir: dirs)
          {
             int nx = x + dir.first;
             int ny = y + dir.second;

             if (nx < 0 || nx >= m || ny < 0 || ny >= n)
               continue;
             
             if (res[nx][ny] > res[x][y] + 1)
             {
                res[nx][ny] = res[x][y] + 1;
                q.push({nx, ny});
             }
          }
        }
        return res;
    }
};
*/

/*
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (mat[i][j] == 0)
              {
                 q.push({i, j});
              }
           }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while(!q.empty())
        {
           auto [x, y] = q.front();
           q.pop();

           for (auto dir: dirs)
           {
              int nx = x + dir.first;
              int ny = y + dir.second;

              if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
              
              // skip 0, and 非 1 
              if (mat[nx][ny] != 1)
                continue;
              
              // 这就是在染色 mat[nx][ny]了
              mat[nx][ny] = 0;
              res[nx][ny] = res[x][y] + 1;

              q.push({nx, ny});
           }
          
        }

        return res;
    }
};

*/

/*
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (mat[i][j] == 0)
              {
                 q.push({i, j});
              }
           }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while(!q.empty())
        {
           auto [x, y] = q.front();
           q.pop();

           for (auto dir: dirs)
           {
              int nx = x + dir.first;
              int ny = y + dir.second;

              if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
              
              // skip   0, and 非 1 
              if (mat[nx][ny] != 1)
                continue;
              
              // 这就是在染色 mat[nx][ny]了
              mat[nx][ny] = 0;
              res[nx][ny] = res[x][y] + 1;
              q.push({nx, ny});
           }
          
        }

        return res;
    }
};

*/

/*
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        const int INF = INT_MAX / 2;
            
        vector<vector<int>> dp(m, vector<int>(n, INF));

        // 初始化：0 的距离为 0
        for (int i = 0 ; i < m; i++)
          for (int j = 0; j < n; j++)
            if (mat[i][j]==0)
              dp[i][j]=0;

        // 第一趟：左上 -> 右下（看上、左）
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
            {
              if (mat[i][j] != 0)
              {
                if (i > 0)
                  dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                if (j > 0)
                  dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
              }
            }
        // 第二趟：右下 -> 左上（看下、右）
        for (int i = m-1; i >= 0; i--)
          for (int j= n-1; j >= 0; j--)
          {
             if (mat[i][j] != 0)
             {
                if (i + 1 < m)
                  dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);

                if (j + 1 < n)
                  dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
             }
          }
        return dp;
    }
};

*/