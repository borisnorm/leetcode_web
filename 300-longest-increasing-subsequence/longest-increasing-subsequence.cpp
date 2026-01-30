class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 定义：dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度

        int n = nums.size();
        // 以nums[i]结尾的数 包括 nums[i]它自己, 所以长度至少都是1
        vector<int> dp(n, 1);

         //不能是0 否则报错
        int maxLen = 1;
        for (int i = 1; i < n; i++)
        {
          for (int j = 0; j < i; j++)
          {
            //dp[i]是 目前已知的，以 nums[i] 结尾的最长递增子序列长度
            //dp[j]+1 是 选择把 nums[i] 接在 nums[j] 后面
            if (nums[j] < nums[i])
              dp[i] = max(dp[i], dp[j]+1);
          }
           
          maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
};
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 定义：dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度

        int n = nums.size();
        // 以nums[i]结尾的数 包括 nums[i]它自己, 所以长度至少都是1
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
          for (int j = 0; j < i; j++)
          {
            //dp[i]是 目前已知的，以 nums[i] 结尾的最长递增子序列长度
            //dp[j]+1 是 选择把 nums[i] 接在 nums[j] 后面
            if (nums[j] < nums[i])
              dp[i] = max(dp[i], dp[j]+1);
          }
        }
        
        int maxLen = 1;
        for (int i = 0; i < dp.size(); i++)
           maxLen = max(maxLen, dp[i]);

        return maxLen;
    }
};
*/
