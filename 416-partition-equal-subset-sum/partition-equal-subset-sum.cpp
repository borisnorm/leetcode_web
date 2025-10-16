class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty())
          return false;
        
        int sum = 0;
        int max_num = 0;

        for (int& x: nums)
        {
           sum+= x;
           max_num = max(max_num, x);
        }

        if (sum & 1 )
          return false;

        int target = sum/2;

        if (max_num > target)
          return false;

        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int& x : nums)
        {
           for (int s = target; s >= x; s--)
             if (dp[s-x])
                dp[s] = 1;
        }

        return dp[target] ? true : false;
    }    
};