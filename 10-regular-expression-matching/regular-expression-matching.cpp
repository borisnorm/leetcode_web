class Solution {
public:
    bool isMatch(string s, string p) {
         int m = s.size();
         int n = p.size();

         vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

         dp[0][0] = true;

         for (int j = 2; j <= n; j++)
           if (p[j-1] == '*')
             dp[0][j] = dp[0][j-2];
    
         auto isMatched = [&](char s_char, char p_char){
            return p_char == '.' || s_char == p_char;
         };

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j-1] != '*')
                {
                   if (isMatched(s[i-1], p[j-1]))
                     dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                   dp[i][j] = dp[i][j-2];

                   if (isMatched(s[i-1], p[j-2]))
                     dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
        }
        
        return dp[m][n];
    }
};