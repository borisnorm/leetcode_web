class Solution {
public:
    bool isSubsequence(string s, string t) {

        int m = s.size();
        int n = t.size();

        int i = 0;
        int j = 0;

        while (i < m && j < n)
        {
          if (s[i] == t[j])
              i++;

          j++;
        }

        return (i == m) ? true : false;
    }
};


/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // base case: empty s
        for (int j = 0; j <= n; j++)
            dp[0][j] = true;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
};

*/