class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n+1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int nodes = 2; nodes <= n; nodes++)
        {
          long long total = 0;
          for (int root = 1; root <= nodes; root++)
          {
             int left = root - 1;
             int right = nodes - root;

             total += dp[left]*dp[right];
          }

          dp[nodes] = total;
        }

        return static_cast<int>(dp[n]);
    }
};