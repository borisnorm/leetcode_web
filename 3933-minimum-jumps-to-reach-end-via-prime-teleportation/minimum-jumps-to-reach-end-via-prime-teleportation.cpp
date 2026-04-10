class Solution
{
public:
    int minJumps(vector<int>& nums)
    {
        int n = (int)nums.size();                                  // 数组长度

        if (n == 1)                                                // 只有一个位置，已经在终点
        {
            return 0;                                              // 不需要跳
        }

        int mx = 0;                                                // 数组中的最大值
        for (int x : nums)                                         // 遍历数组
        {
            mx = max(mx, x);                                       // 更新最大值
        }

        vector<int> spf(mx + 1, 0);                                // spf[x] 表示 x 的最小质因子

        for (int i = 2; i <= mx; i++)                              // 从 2 开始筛
        {
            if (spf[i] == 0)                                       // 如果还没有被标记，说明 i 是质数
            {
                spf[i] = i;                                        // 质数的最小质因子就是自己

                if ((long long)i * i <= mx)                        // 防止越界，并且从 i*i 开始筛
                {
                    for (long long j = 1LL * i * i; j <= mx; j += i) // 枚举 i 的倍数
                    {
                        if (spf[(int)j] == 0)                      // 如果该数还没被标记
                        {
                            spf[(int)j] = i;                       // 它的最小质因子记为 i
                        }
                    }
                }
            }
        }

        vector<vector<int>> bucket(mx + 1);                        // bucket[p] = 所有 nums[idx] 能被质数 p 整除的下标

        for (int i = 0; i < n; i++)                                // 遍历每个下标
        {
            int x = nums[i];                                       // 当前值
            while (x > 1)                                          // 开始分解质因子
            {
                int p = spf[x];                                    // 取当前最小质因子
                bucket[p].push_back(i);                            // 说明 nums[i] 能被 p 整除，下标 i 放入 bucket[p]

                while (x % p == 0)                                 // 跳过同一个质因子的重复次数
                {
                    x /= p;                                        // 不断除掉 p
                }
            }
        }

        vector<int> dist(n, -1);                                   // dist[i] = 从 0 跳到 i 的最少步数
        vector<char> usedPrime(mx + 1, 0);                         // usedPrime[p] = prime p 的传送是否已经处理过
        queue<int> q;                                              // BFS 队列

        dist[0] = 0;                                               // 起点距离为 0
        q.push(0);                                                 // 起点入队

        while (!q.empty())                                         // 标准 BFS
        {
            int i = q.front();                                     // 取出当前下标
            q.pop();                                               // 出队

            int d = dist[i];                                       // 当前下标的最短距离

            if (i == n - 1)                                        // 如果已经到终点
            {
                return d;                                          // 直接返回最少步数
            }

            if (i - 1 >= 0 && dist[i - 1] == -1)                   // 尝试向左走一步
            {
                dist[i - 1] = d + 1;                               // 记录距离
                q.push(i - 1);                                     // 入队
            }

            if (i + 1 < n && dist[i + 1] == -1)                    // 尝试向右走一步
            {
                dist[i + 1] = d + 1;                               // 记录距离
                q.push(i + 1);                                     // 入队
            }

            int val = nums[i];                                     // 当前下标对应的值

            if (val >= 2 && spf[val] == val && !usedPrime[val])    // 只有当前值本身是质数，且这个 prime 还没用过，才能传送
            {
                usedPrime[val] = 1;                                // 标记这个 prime 已经处理过

                for (int nxt : bucket[val])                        // 枚举所有能被 val 整除的位置
                {
                    if (dist[nxt] == -1)                           // 如果该位置还没访问过
                    {
                        dist[nxt] = d + 1;                         // 传送一次，距离加 1
                        q.push(nxt);                               // 入队
                    }
                }
            }
        }

        return -1;                                                 // 理论上一定可达，这里只是保险返回
    }
};
