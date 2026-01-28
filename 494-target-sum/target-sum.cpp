class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int x: nums)
          sum += x;
        
        // 分成 left[正数] subset 与 right[负数] subset
        // left[正数] - right[负数] = sum
        // left[正数] + right[负数] = target
        // left + left - sum  = target
        // left = (target + sum) /2
        if ((sum +  target) % 2 != 0 || sum < abs(target))
          return 0;

        int left = (sum + target) / 2;

        vector<int> dp(left+1, 0);
        dp[0] = 1; // 方法数 dp[0] 表示存在性 
        // dp 表示 构成当前这 容量 j 的方案数, 

        for (int num: nums)
        { 
        
          //dp[j] = dp[0] + dp[1] + dp[2]..dp[j-num];
          // 有当前这个 num 的这个 容量 + dp[j - num] 的容量的方案 构成.
          // left 是 求人 4 的 容量 方案
          // 那么 nums = { 容量 1, 2, 3, 4}
          //  dp 表示 选了 容量 4 后, 剩余的 dp[4-4]的容量数 +
          //         选了 容量 3 后, 剩余的 dp[4-3]的容量数 +
          //          .............
          // j 一直在 --, 也就是 选择了 num 后 这个物品后,  容量 一直在 更新
          // 上几层的值, 可能被用到当前层  
          for (int j = left; j >= num; j--)
            dp[j] += dp[j-num];
        }

        return dp[left];
    }
};