class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<int> dp(high + 1, 0);

        // dp[i] 表示构建 长度为 i 的字符串的方案数
        dp[0] = 1;

        for (int i = 1; i <= high; i++)
        {
           if (i >= zero)
             dp[i] = (dp[i] + dp[i-zero]) % MOD;
           
           if (i >= one)
             dp[i] = (dp[i] + dp[i-one]) % MOD;
        }

        int res = 0;
        // 所有 字符串长度在 [low, high] 范围内的 方案数 的累加
        for (int i = low; i <= high; i++)
          res = (res + dp[i]) % MOD;

        return res;

    }
};