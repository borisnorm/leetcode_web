class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
          return 0;
          
        int n = nums.size();
        if (n==1)
          return nums[0];

        if (n==2)
          return max(nums[0], nums[1]);
        
        // [0, n-2]  [1, n-1]

        return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));
    } 

    int robRange(vector<int>& nums, int l, int r)
    {
        int n = r - l + 1;
        vector<int> dp(n, 0);

        dp[0] = nums[l];
        dp[1] = max(nums[l], nums[l+1]);

        for (int i = 2; i < n; i++)
          dp[i] = max(dp[i-1], dp[i-2]+nums[l+i]);

        return dp[n-1];
    }

    
};