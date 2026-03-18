class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<long long, int>> dp(n);

        int res = 0;
        
        for (int i = 1; i < n; i++)
        {

          for (int j = 0; j < i; j++)
          {
             long long d = (long long)nums[i] - nums[j];
            
             int cnt = 0;
             if (dp[j].count(d))
              cnt = dp[j][d];
            
             res += cnt;

             dp[i][d] += cnt + 1;

          }
        }

        return res;
    }
};