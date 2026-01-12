class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // dp[i][j] = number of distinct subsequences of s[0..i-1] that equal t[0..j-1]
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        
        // Base case: empty t can be formed in one way
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Always have the option to not use s[i-1]
                dp[i][j] = dp[i-1][j];
                
                // If characters match, we can also use s[i-1]
                if (s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        
        return dp[m][n];
    }
};