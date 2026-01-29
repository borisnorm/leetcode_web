class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
       
         vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

         for (auto str: strs)
         {
            int zero_cnt = 0;
            int one_cnt = 0;

            for (auto c: str)
            {
                if (c == '0')
                  zero_cnt++;
                else
                  one_cnt++;
            }

            for (int i = m; i >= zero_cnt; i--)
            {
                for (int j = n; j >= one_cnt; j--)
                {
                    //dp[i][j] = 最多用 i 个 0、j 个 1 时，最多能选多少个字符串
                    // m = 5, n = 3, {"0000111", "0","00","1","10"}
                    //dp[4][3] = max(0, dp[0][0]+1=1) = 1
                    //dp[5][3] = max(0, dp[1][0]+1=1) = 1
                    //含义：容量够大（(4,3)/(5,3)）时，可以选这个大串 1 个。
                    dp[i][j] = max(dp[i][j],  dp[i-zero_cnt][j-one_cnt] + 1);
                }
            }
         }
         
         // 时间复杂度 O(len(strs) x m x n )
         // 空间复杂度 O(m x n)


         return dp[m][n];
    }
};