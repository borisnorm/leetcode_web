class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const long long LIM = (long long)INT_MAX; // 最终返回 int，就截到这里
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int s = 1; s <= target; s++) {
            long long cur = 0;
            for (int x : nums) {
                if (s >= x) {
                    cur += dp[s - x];
                    if (cur >= LIM) { // 防止 cur 继续涨到 long long 溢出
                        cur = LIM;
                        break;
                    }
                }
            }
            dp[s] = cur;
        }
        return (int)dp[target];
    }
};
