
class Solution
{
public:
    int m;                              // 矩阵行数
    int n;                              // 矩阵列数
    vector<vector<int>> memo;           // memo[i][j] 表示从 (i, j) 出发的最长递增路径长度
    vector<vector<int>> dirs;           // 四个方向

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        if (matrix.empty() || matrix[0].empty())   // 如果矩阵为空
        {
            return 0;                              // 直接返回 0
        }

        m = matrix.size();                         // 记录行数
        n = matrix[0].size();                      // 记录列数

        memo.assign(m, vector<int>(n, 0));        // 初始化 memo，0 表示还没有计算过
        dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};// 下、上、右、左四个方向

        int ans = 0;                               // 记录全局最长路径长度

        for (int i = 0; i < m; i++)                // 枚举每一个起点行
        {
            for (int j = 0; j < n; j++)            // 枚举每一个起点列
            {
                ans = max(ans, dfs(matrix, i, j)); // 取所有起点中的最大值
            }
        }

        return ans;                                // 返回最终答案
    }

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if (memo[i][j] != 0)                       // 如果这个状态已经算过
        {
            return memo[i][j];                     // 直接返回记忆化结果
        }

        int best = 1;                              // 至少包含当前格子自己，所以初始长度为 1

        for (auto& d : dirs)                       // 枚举四个方向
        {
            int ni = i + d[0];                     // 邻居行坐标
            int nj = j + d[1];                     // 邻居列坐标

            if (ni < 0 || ni >= m || nj < 0 || nj >= n) // 如果越界
            {
                continue;                          // 跳过这个方向
            }

            if (matrix[ni][nj] <= matrix[i][j])    // 如果不是严格递增
            {
                continue;                           // 不能走，跳过
            }

            best = max(best, 1 + dfs(matrix, ni, nj)); // 当前格子接上邻居的最长路径
        }

        memo[i][j] = best;                         // 记忆化保存结果
        return best;                               // 返回从当前格子出发的最长递增路径长度
    }
};

/*
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // dfs 
         
        if (matrix.empty() || matrix[0].empty())
          return 0;
        //求的是最长子序列, 不是从最大值 到 最小值
        int m = matrix.size();
        int n = matrix[0].size();

        int maxLen = 1;
        int len = 1; // len 要包括第一个节点的, 包括它自己

        for (int i = 0; i < m; i++)
        {
          for (int j = 0; j < n; j++)
          {
             dfs(matrix, i, j, len, maxLen);
          }
        }

        return maxLen;
    }

    void dfs(vector<vector<int>>& matrix, int i, int j, int len, int& maxLen)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n)
          return;

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto dir : dirs)
        {
           int nI = i + dir.first;
           int nJ = j + dir.second;

           if (nI < 0 || nI >= m || nJ < 0 || nJ >= n)
             continue;

           if (matrix[nI][nJ] <= matrix[i][j])
            continue;
           
           maxLen = max(maxLen, len + 1);
           dfs(matrix, nI, nJ, len + 1, maxLen);
        }

    }
};

*/