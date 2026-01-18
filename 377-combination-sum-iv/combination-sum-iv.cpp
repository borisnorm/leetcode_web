class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const long long LIM = (long long)INT_MAX; // 最终返回 int，就截到这里
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) 
        {
            long long cur = dp[i];

            for (int num : nums) 
            {
                if (i - num >= 0) 
                {
                    cur += dp[i - num];
                    if (cur >= LIM) // 防止 cur 继续涨到 long long 溢出
                    { 
                        cur = LIM;
                        break;
                    }
                }
            }
            dp[i] = cur;
        }
        return (int)dp[target];
    }
};

/*
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        

         vector<unsigned long long> dp(target + 1, 0);
         dp[0] = 1;

         for (int i = 1; i <= target; i++)
         {
            for (int num : nums)
            {
                if (i - num >= 0)
                {
                   //dp[i] 表示 不选
                   //dp[i-num] 表示 选了 num 后 剩余的 方案数
                   dp[i] = dp[i] + dp[i-num];
                }
            }

         }

         return dp[target];
    }
};
*/