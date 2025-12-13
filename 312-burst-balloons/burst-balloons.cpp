class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for (int len = 2; len < n + 2; len++)
        {
           for (int left = 0; left + len < n + 2;  left++)
           {
              int right = left + len;
              for (int k = left + 1; k < right; k++)
              {
                 dp[left][right] = max(dp[left][right], 
                                       dp[left][k] + nums[left] * nums[k] * nums[right] + dp[k][right]);
              }
           }
        }

        return dp[0][n+1];
    }
};