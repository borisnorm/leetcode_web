class Solution
{
public:
    int numberOfStableArrays(int zero, int one, int limit)
    {
        const int MOD = 1000000007;   // 题目要求对 1e9+7 取模

        // dp0[i][j]:
        // 中文：使用 i 个 0 和 j 个 1，且最后一个元素为 0 的稳定数组个数
        // English: number of stable arrays using i zeros and j ones, ending with 0
        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));   // 初始化为 0

        // dp1[i][j]:
        // 中文：使用 i 个 0 和 j 个 1，且最后一个元素为 1 的稳定数组个数
        // English: number of stable arrays using i zeros and j ones, ending with 1
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));   // 初始化为 0

        // 处理只有 0、没有 1 的情况
        // 只要 i <= limit，那么全是 0 的数组是合法的，只有 1 种
        for (int i = 1; i <= zero && i <= limit; ++i)
        {
            dp0[i][0] = 1;   // 例如 000...0
        }

        // 处理只有 1、没有 0 的情况
        // 只要 j <= limit，那么全是 1 的数组是合法的，只有 1 种
        for (int j = 1; j <= one && j <= limit; ++j)
        {
            dp1[0][j] = 1;   // 例如 111...1
        }

        // 枚举用了多少个 0
        for (int i = 1; i <= zero; ++i)
        {
            // 枚举用了多少个 1
            for (int j = 1; j <= one; ++j)
            {
                // 计算 dp0[i][j]
                // 递推式：
                // dp0[i][j] = dp0[i-1][j] + dp1[i-1][j] - dp1[i-limit-1][j]
                // 含义：
                // 从 dp0[i-1][j] 的滑动区间和扩展而来，
                // 新加入 dp1[i-1][j]，如果窗口超长，则移除 dp1[i-limit-1][j]

                long long waysEndWith0 = 0;   // 暂存 dp0[i][j]

                waysEndWith0 = dp0[i - 1][j];         // 先继承前一个 i 的区间和
                waysEndWith0 += dp1[i - 1][j];        // 加入新进入窗口的项

                if (i - limit - 1 >= 0)               // 如果区间长度超过 limit
                {
                    waysEndWith0 -= dp1[i - limit - 1][j];   // 减去滑出窗口的项
                }

                waysEndWith0 = (waysEndWith0 + MOD) % MOD;        // 先取模
                //if (waysEndWith0 < 0)                 // 防止出现负数
                //{
                //    waysEndWith0 += MOD;              // 调整回正数范围
                //}

                dp0[i][j] = static_cast<int>(waysEndWith0);   // 写回 dp0

                // 计算 dp1[i][j]
                // 递推式：
                // dp1[i][j] = dp1[i][j-1] + dp0[i][j-1] - dp0[i][j-limit-1]
                // 含义和上面对称

                long long waysEndWith1 = 0;   // 暂存 dp1[i][j]

                waysEndWith1 = dp1[i][j - 1];         // 先继承前一个 j 的区间和
                waysEndWith1 += dp0[i][j - 1];        // 加入新进入窗口的项

                if (j - limit - 1 >= 0)               // 如果区间长度超过 limit
                {
                    waysEndWith1 -= dp0[i][j - limit - 1];   // 减去滑出窗口的项
                }

                waysEndWith1 = (waysEndWith1 + MOD) % MOD;

                /*
                waysEndWith1 %= MOD;                  // 先取模
                if (waysEndWith1 < 0)                 // 防止出现负数
                {
                    waysEndWith1 += MOD;              // 调整回正数范围
                }
                */

                dp1[i][j] = static_cast<int>(waysEndWith1);   // 写回 dp1
            }
        }

        // 最终答案 = 以 0 结尾的方案数 + 以 1 结尾的方案数
        long long ans = 0;                           // 用 long long 防止加法溢出
        ans += (dp0[zero][one] + dp1[zero][one]) % MOD;                     // 加上以 0 结尾的方案数
                        // 加上以 1 结尾的方案数
                            // 最后取模

        return static_cast<int>(ans);                // 返回答案
    }
};