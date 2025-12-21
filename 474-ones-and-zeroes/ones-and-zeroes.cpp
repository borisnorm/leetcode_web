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
                    dp[i][j] = max(dp[i][j],  dp[i-zero_cnt][j-one_cnt] + 1);
                }
            }
         }


         return dp[m][n];
    }
};