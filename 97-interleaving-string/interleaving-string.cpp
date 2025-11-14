class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s1.empty() && s2.empty() && s3.empty())
           return true;

        int m = s1.size();
        int n = s2.size();

        if (m + n != s3.size())
          return false;

        vector<vector<int>> dp(m+1, vector<int>(n+1, false));

        dp[0][0] = true;
        for (int i = 1; i <= m; i++)
          dp[i][0] = dp[i-1][0] && (s3[i-1] == s1[i-1]);

        for (int j = 1; j <= n; j++)
          dp[0][j] = dp[0][j-1] && (s3[j-1] == s2[j-1]);

        
        for (int i = 1; i <= m; i++)
          for (int j = 1; j <= n; j++)
          {
            char c = s3[i + j -1];
            bool isFromS1  = dp[i-1][j] && (s1[i-1] == c);
            bool isFromS2  = dp[i][j-1] && (s2[j-1] == c);
            dp[i][j] = isFromS1 || isFromS2;  
          }

        return dp[m][n];
    }
};