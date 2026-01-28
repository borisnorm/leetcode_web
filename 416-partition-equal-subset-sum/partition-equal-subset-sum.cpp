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

        int target = sum/2;

        if (sum & 0x1) // 奇数的 sum, 平分到2个 subset 里面去
          return false;

        if (max_num > target)  // max_num 太大 也无法平分
          return false;

        vector<int> dp(target+1, 0);
        dp[0] = 1;

        int n = nums.size();
        //for (int& num : nums)
        for (int i = 0; i < n; i++)
        {
           int num = nums[i];
            // 上一行 的 nums[i] 计算出来的 dp[sum] 会被 下一行所使用
           
           // 下面判断的是 sum - num >= 0 才可以
           for (int sum = target; sum >= num; sum--)
           {
            
              dp[sum] =  dp[sum] || dp[sum-num];
              //if (dp[sum - num])
              //  dp[sum] = 1;
           }
        }

        return dp[target] ? true : false;
    }    
};