class Solution
{
public:
    vector<int> memo;    // 记忆化数组，memo[t] 表示到达 t 的最少指令数

    int racecar(int target)
    {
        memo.assign(target + 1, -1);          // 初始化记忆化数组，-1 表示尚未计算
        return dfs(target);                   // 返回目标 target 的最优解
    }

    int dfs(int t)
    {
        if (t == 0)                           // 如果目标是 0，说明已经到达，不需要任何操作
        {
            return 0;                         // 返回 0
        }

        if (memo[t] != -1)                    // 如果该状态已经计算过
        {
            return memo[t];                   // 直接返回记忆化结果
        }

        int k = 1;                            // k 表示连续加速次数
        while ((1 << k) - 1 < t)              // 找最小的 k，使得 2^k - 1 >= t
        {
            k++;                              // 不够就继续增大 k
        }

        int full = (1 << k) - 1;              // 连续 k 次 A 后到达的位置 2^k - 1

        if (full == t)                        // 如果刚好等于目标
        {
            memo[t] = k;                      // 只需要 k 次 A
            return memo[t];                   // 返回答案
        }

        int ans = k + 1 + dfs(full - t);      // 方案1：冲过头后 R 一次，再解决剩余距离

        int pre = (1 << (k - 1)) - 1;         // 连续 k-1 次 A 后到达的位置

        for (int m = 0; m < k - 1; m++)       // 枚举回拉 m 次 A
        {
            int back = (1 << m) - 1;          // 反方向连续 m 次 A 后走过的距离
            int remain = t - (pre - back);    // 当前策略下还剩多少距离没到达
            int steps = (k - 1) + 1 + m + 1;  // 总固定步数：前进(k-1) + R + 后退m + R
            ans = min(ans, steps + dfs(remain)); // 更新最优解
        }

        memo[t] = ans;                        // 记忆化保存答案
        return memo[t];                       // 返回答案
    }
};