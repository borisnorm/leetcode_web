class Solution
{
public:
    int minCost(vector<vector<int>>& grid, int k)
    {
        int m = (int)grid.size();                                       // 网格行数
        int n = (int)grid[0].size();                                    // 网格列数

        int maxVal = 0;                                                 // 记录网格中的最大值
        for (int i = 0; i < m; ++i)                                     // 遍历每一行
        {
            for (int j = 0; j < n; ++j)                                 // 遍历每一列
            {
                maxVal = max(maxVal, grid[i][j]);                       // 更新最大值
            }
        }

        const int INF = numeric_limits<int>::max() / 4;                 // 一个足够大的数，避免加法溢出

        vector<vector<int>> prev(m, vector<int>(n, INF));               // prev 表示上一层 dp[t-1]
        vector<vector<int>> cur(m, vector<int>(n, INF));                // cur 表示当前层 dp[t]

        prev[0][0] = 0;                                                 // 起点成本为 0

        for (int i = 0; i < m; ++i)                                     // 先计算 t = 0 的情况
        {
            for (int j = 0; j < n; ++j)                                 // 遍历所有格子
            {
                if (i == 0 && j == 0)                                   // 起点跳过
                {
                    continue;                                           // 不需要更新
                }

                if (i > 0)                                              // 如果可以从上方过来
                {
                    prev[i][j] = min(prev[i][j], prev[i - 1][j] + grid[i][j]); // 上方转移
                }

                if (j > 0)                                              // 如果可以从左方过来
                {
                    prev[i][j] = min(prev[i][j], prev[i][j - 1] + grid[i][j]); // 左方转移
                }
            }
        }

        int ans = prev[m - 1][n - 1];                                   // 先用 0 次 teleport 的答案初始化

        for (int t = 1; t <= k; ++t)                                    // 枚举 teleport 次数
        {
            vector<int> bestAtVal(maxVal + 1, INF);                     // bestAtVal[v] = 上一层中值恰好为 v 的最小代价
            vector<int> suf(maxVal + 2, INF);                           // suf[v] = 上一层中值 >= v 的最小代价

            for (int i = 0; i < m; ++i)                                 // 遍历所有格子
            {
                for (int j = 0; j < n; ++j)                             // 统计每个值对应的最小上一层代价
                {
                    int v = grid[i][j];                                 // 当前格子的值
                    bestAtVal[v] = min(bestAtVal[v], prev[i][j]);       // 更新 bestAtVal[v]
                }
            }

            suf[maxVal] = bestAtVal[maxVal];                            // 初始化后缀最小值边界
            for (int v = maxVal - 1; v >= 0; --v)                       // 从大到小做后缀最小值
            {
                suf[v] = min(bestAtVal[v], suf[v + 1]);                 // 所有值 >= v 的最小代价
            }

            for (int i = 0; i < m; ++i)                                 // 先用 teleport 初始化当前层
            {
                for (int j = 0; j < n; ++j)                             // 遍历每个格子
                {
                    int v = grid[i][j];                                 // 当前格子的值
                    cur[i][j] = suf[v];                                 // 可从任意值 >= v 的格子免费 teleport 到这里
                }
            }

            cur[0][0] = min(cur[0][0], 0);                              // 起点仍然可以视为成本 0

            for (int i = 0; i < m; ++i)                                 // 再在当前层做普通移动的 DP 扩散
            {
                for (int j = 0; j < n; ++j)                             // 遍历所有格子
                {
                    if (i == 0 && j == 0)                               // 起点跳过
                    {
                        continue;                                       // 不需要更新
                    }

                    if (i > 0)                                          // 如果可以从上方走过来
                    {
                        cur[i][j] = min(cur[i][j], cur[i - 1][j] + grid[i][j]); // 上方普通移动转移
                    }

                    if (j > 0)                                          // 如果可以从左方走过来
                    {
                        cur[i][j] = min(cur[i][j], cur[i][j - 1] + grid[i][j]); // 左方普通移动转移
                    }
                }
            }

            ans = min(ans, cur[m - 1][n - 1]);                          // 更新最终答案
            prev.swap(cur);                                             // 当前层变成下一轮的上一层

            for (int i = 0; i < m; ++i)                                 // 清空 cur，准备下一轮使用
            {
                fill(cur[i].begin(), cur[i].end(), INF);                // 重新设为 INF
            }
        }

        return ans;                                                     // 返回答案
    }
};