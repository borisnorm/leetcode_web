class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // dp[i][j]:
        // the maximum number of uncrossed lines
        // between nums1[0..i-1] and nums2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    // connect these two points
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // skip one side
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};
