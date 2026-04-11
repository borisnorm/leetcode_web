class Solution
{
public:
    int minJumps(vector<int>& nums)
    {
        int n = (int)nums.size();                                  
        if (n == 1)                   // 只有一个位置，已经在终点
            return 0;                 // 不需要跳

        int maxVal = 0;               // 数组中的最大值
        for (int x : nums)            // 遍历数组
          maxVal = max(maxVal, x);    // 更新最大值
        //Smallest Prime Factor
        vector<int> smallPrimeFactors(maxVal + 1, 0);   // smallPrimeFactor[x] 表示 x 的最小质因子

        for (int i = 2; i <= maxVal; i++)
        {
           if (smallPrimeFactors[i] != 0)  // 如果还没有被标记，说明 i 是质数
             continue;
          
           // 下面的 将 以 i 这个质数为底的 合数 给赋值
           // 正好对应上面的检查
           smallPrimeFactors[i] = i;        // 质数的最小质因子就是自己
           if ((long long)i * i <= maxVal)  // 防止越界，并且从 i*i 开始筛
           {
             for (long long j = 1LL * i * i; j <= maxVal; j += i)
             {
               if (smallPrimeFactors[j] == 0)    //如果该数还没被标记
                 smallPrimeFactors[j] = i;      // 它的最小质因子记为 i
             }
           }
           
        }
        
        // prime Num 跳转后的 位置
        vector<vector<int>> bucket(maxVal + 1);  // bucket[p] = 所有 nums[idx] 能被质数 p 整除的下标
        for (int i = 0; i < n; i++)              
        {
            int x = nums[i];
            while (x > 1)             // 开始分解质因子
            {
                int p = smallPrimeFactors[x]; // 取当前最小质因子
                bucket[p].push_back(i);       // 说明 nums[i] 能被 p 整除，下标 i 放入 bucket[p]
                while (x % p == 0)            // 跳过同一个质因子的重复次数
                    x /= p;                   // 不断除掉 p
            }
        }

        vector<int> dist(n, -1);                 // dist[i] = 从 0 跳到 i 的最少步数
        vector<char> usedPrime(maxVal + 1, 0);  // usedPrime[p] = prime p 的传送是否已经处理过
        queue<int> q;                           // BFS 队列

        dist[0] = 0;   // 起点距离为 0
        q.push(0);     // 起点入队

        while (!q.empty())      // 标准 BFS
        {
            int i = q.front();  // 取出当前下标
            q.pop();            // 出队

            int d = dist[i];    // 当前下标的最短距离
            if (i == n - 1)     // 如果已经到终点
                return d;       // 直接返回最少步数

            if (i - 1 >= 0 && dist[i - 1] == -1)  // 尝试向左走一步
            {
                dist[i - 1] = d + 1; // 记录距离
                q.push(i - 1);       // 入队
            }

            if (i + 1 < n && dist[i + 1] == -1)  // 尝试向右走一步
            {
                dist[i + 1] = d + 1;    // 记录距离
                q.push(i + 1);          // 入队
            }

            int val = nums[i];          // 当前下标对应的值
            // 只有当前值本身是质数，且这个 prime 还没用过，才能传送
            if (val >= 2 && smallPrimeFactors[val] == val && !usedPrime[val])    
            {
                usedPrime[val] = 1;           // 标记这个 prime 已经处理过
                for (int nxt : bucket[val])   // 枚举所有能被 val 整除的位置
                {
                    if (dist[nxt] == -1)      // 如果该位置还没访问过
                    {
                        dist[nxt] = d + 1;    // 传送一次，距离加 1
                        q.push(nxt);          // 入队
                    }
                }
            }
        }

        return -1;   // 理论上一定可达，这里只是保险返回
    }
};