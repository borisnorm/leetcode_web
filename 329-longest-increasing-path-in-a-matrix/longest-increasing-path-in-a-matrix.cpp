
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         
        if (matrix.empty() || matrix[0].empty())
          return 0;
        //求的是最长子序列, 不是从最大值 到 最小值
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, -1));
        int maxLen = 1;
        int len = 1; // len 要包括第一个节点的, 包括它自己

        for (int i = 0; i < m; i++)
        {
          for (int j = 0; j < n; j++)
          {
             maxLen = max(maxLen, dfs(matrix, i, j, memo));
          }
        }

        return maxLen;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int best = 1;

        if (memo[i][j] != -1)
          return memo[i][j];

        if (i < 0 || i >= m || j < 0 || j >= n)
          return 0;

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto dir : dirs)
        {
           int nI = i + dir.first;
           int nJ = j + dir.second;

           if (nI < 0 || nI >= m || nJ < 0 || nJ >= n)
             continue;

           if (matrix[nI][nJ] <= matrix[i][j])
            continue;
            
           best = max(best, 1 + dfs(matrix, nI, nJ, memo));
        }

        memo[i][j] = best;
        return best;
    }
};
