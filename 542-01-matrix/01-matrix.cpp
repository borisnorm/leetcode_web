#include <bits/stdc++.h>
using namespace std;

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
