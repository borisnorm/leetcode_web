class Solution
{
public:
    // 判断是否是质数
    bool isPrime(int x)
    {
        if (x < 2) return false;
        for (int i = 2; (long long)i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }

    int minJumps(vector<int>& nums)
    {
        int n = nums.size();

        // prime p -> 虚节点编号(从n开始)
        unordered_map<int, int> pId;
        int vCnt = n;

        // 虚节点 -> 所有 nums[j] % p == 0 的实节点j
        unordered_map<int, vector<int>> pNodes;

        // 建虚节点：遍历所有j，找哪些质数能"传送到j"
        // 即对每个j，枚举nums[j]的质因子p
        // 因为只有nums[i]==p时才能传送，所以p必须出现在nums里
        // 但建图时：虚节点p -> j 的条件是 nums[j]%p==0
        // 发起端：只有nums[i]是质数时，i才能连到虚节点nums[i]

        // 第一步：找所有出现在nums里的质数p，作为虚节点
        // 第二步：对每个j，枚举nums[j]的质因子，若该质因子在nums中出现过，建虚→实边

        // 收集nums中所有质数
        unordered_map<int, bool> primeInNums;
        for (int i = 0; i < n; i++)
        {
            if (isPrime(nums[i]))
                primeInNums[nums[i]] = true;
        }

        // 对每个j，枚举质因子p，若p在nums中作为质数出现，建虚节点p->j
        for (int j = 0; j < n; j++)
        {
            int x = nums[j];
            // 分解质因子
            vector<int> factors;
            for (int f = 2; (long long)f * f <= x; f++)
            {
                if (x % f == 0)
                {
                    factors.push_back(f);
                    while (x % f == 0) x /= f;
                }
            }
            if (x > 1) factors.push_back(x);

            for (int p : factors)
            {
                if (!primeInNums.count(p)) continue; // 该质数未在nums出现，无法传送
                if (!pId.count(p))
                    pId[p] = vCnt++;          // 分配虚节点编号
                pNodes[pId[p]].push_back(j);  // 虚节点p -> 实节点j
            }
        }

        // 0-1 BFS
        vector<int> dist(vCnt, INT_MAX);
        dist[0] = 0;
        deque<pair<int,int>> dq; // {dist, node}
        dq.push_back({0, 0});

        while (!dq.empty())
        {
            auto [d, u] = dq.front();
            dq.pop_front();

            if (d > dist[u]) continue; // 过期节点跳过

            if (u < n)
            {
                // 实→实 i±1，代价1
                for (int nb : {u-1, u+1})
                {
                    if (nb >= 0 && nb < n && dist[nb] > d + 1)
                    {
                        dist[nb] = d + 1;
                        dq.push_back({d+1, nb});
                    }
                }
                // 实→虚：只有nums[u]本身是质数才能传送，代价1
                if (isPrime(nums[u]) && pId.count(nums[u]))
                {
                    int v = pId[nums[u]];
                    if (dist[v] > d + 1)
                    {
                        dist[v] = d + 1;
                        dq.push_back({d+1, v});
                    }
                }
            }
            else
            {
                // 虚→实，代价0，队头
                auto& nb = pNodes[u];
                for (int r : nb)
                {
                    if (dist[r] > d)
                    {
                        dist[r] = d;
                        dq.push_front({d, r});
                    }
                }
                nb.clear(); // 防重复遍历
            }
        }

        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }
};