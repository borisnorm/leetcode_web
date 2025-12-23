class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
         if (nums.empty())
           return 0;
        
         int n = nums.size();

         vector<int> dp(n, 1);
         vector<int> cnt(n, 1);

         int maxLen = 0;
         unordered_map<int, int> len2cnt;
         for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < i; j++)
            {
              if (nums[j] < nums[i])
              {
                  if (dp[j] + 1 > dp[i])
                  {
                     dp[i] = dp[j] + 1;
                     // 路径扩展是“按结尾位置 i”发生的，不是“按长度”发生的。
                     cnt[i] = cnt[j];
                  }
                  else if (dp[j] + 1 == dp[i])
                  {
                      cnt[i] += cnt[j];
                  }
              }
                
            }

            maxLen = max(maxLen, dp[i]);
         }

         int maxCnt = 0;
        
         for (int i = 0; i < n; i++)
         {
            if (dp[i] == maxLen)
              maxCnt += cnt[i];
         }

         return maxCnt;

    }
};