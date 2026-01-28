class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty())
          return false;
        
        int sum = 0;
        int max_num = 0;

        for (int& num: nums)
        {
           sum += num;
           max_num = max(max_num, num);
        }

        if (sum & 1)
          return false;

        int target = sum/2;

        if (max_num > target)
          return false;

        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int& num : nums)
        {
           for (int sum = target; sum >= num; sum--)
             if (dp[sum - num])
                dp[sum] = 1;
        }

        return dp[target] ? true : false;
    }    
};