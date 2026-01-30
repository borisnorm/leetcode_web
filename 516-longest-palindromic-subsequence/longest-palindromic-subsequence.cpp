class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 0)
          return 0;
        
        //dp[i][j] s[i...j] 范围内的回文子序列长度
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // i = j 的时候 长度 为 1
        for (int i = 0; i < n; i++)
          dp[i][i] = 1;

         // i 的遍历方向 是有推导公式中的 dp[i+1][j-1]决定的
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                  // i..........j
                  //  i+1...j-1
                  // 2个字符相同, 同时收缩 长度+2
                  dp[i][j] = dp[i+1][j-1] + 2; 
                }
                else
                {
                    // i...........j
                    //  i+1........j

                    // i...........j
                    // i.........j-1
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

         // dp[i][j]是 s[i...j]的最长回文子串的长度
         // dp[0][n-1] 是 s[0...n-1]的最长回文子串
        return dp[0][n-1];
    }
};