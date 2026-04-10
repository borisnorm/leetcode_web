class Solution
{
public:
    struct UnionFind
    {
        vector<int> parent;             // parent[i] 表示节点 i 的父节点
        vector<int> rankv;              // rankv[i] 用于按秩合并，减少树高

        UnionFind(int n)
        {
            parent.resize(n);           // 分配 parent 大小
            rankv.assign(n, 0);         // 初始秩都为 0
            iota(parent.begin(), parent.end(), 0); // 每个点初始父节点都是自己
        }

        int find(int x)
        {
            if (parent[x] != x)         // 如果当前点不是根
            {
                parent[x] = find(parent[x]); // 路径压缩
            }

            return parent[x];           // 返回根节点
        }

        void unite(int x, int y)
        {
            int rx = find(x);           // 找到 x 的根
            int ry = find(y);           // 找到 y 的根

            if (rx == ry)               // 如果已经在同一个集合
            {
                return;                 // 直接返回
            }

            if (rankv[rx] < rankv[ry])  // 如果 rx 的秩更小
            {
                parent[rx] = ry;        // 把 rx 挂到 ry 下面
            }
            else if (rankv[rx] > rankv[ry]) // 如果 ry 的秩更小
            {
                parent[ry] = rx;        // 把 ry 挂到 rx 下面
            }
            else                        // 如果两边秩相同
            {
                parent[ry] = rx;        // 任意挂一个，这里让 ry 挂到 rx
                rankv[rx]++;            // 根的秩加一
            }
        }

        void reset(int x)
        {
            parent[x] = x;              // 把 x 重置成单独集合
        }
    };

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
    {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b)
             {
                 return a[2] < b[2];    // 按时间从小到大排序
             });

        UnionFind uf(n);                // 创建并查集

        uf.unite(0, firstPerson);       // 0 和 firstPerson 在时间 0 就知道秘密，所以先连起来

        int m = static_cast<int>(meetings.size()); // 会议数量
        int i = 0;                      // 扫描指针

        while (i < m)                   // 按时间分组处理
        {
            int t = meetings[i][2];     // 当前时间
            int j = i;                  // j 用来找到同时间组的右边界

            while (j < m && meetings[j][2] == t) // 找到所有时间为 t 的会议
            {
                j++;
            }

            unordered_set<int> people;  // 保存当前时间组涉及到的所有人

            for (int k = i; k < j; k++) // 先把当前时间组全部 union
            {
                int x = meetings[k][0]; // 当前会议第一个人
                int y = meetings[k][1]; // 当前会议第二个人

                uf.unite(x, y);         // 同一时间组内先连通
                people.insert(x);       // 记录参与者 x
                people.insert(y);       // 记录参与者 y
            }

            int root0 = uf.find(0);     // 当前知道秘密的连通块根（本质上看是否和 0 连通）

            for (int person : people)   // 检查当前时间组所有参与者
            {
                if (uf.find(person) != root0) // 如果这个人不和 0 连通
                {
                    uf.reset(person);   // 说明这一时间组没有接触到秘密，撤销他的临时连接
                }
            }

            i = j;                      // 进入下一组时间
        }

        vector<int> ans;                // 结果数组

        int root0 = uf.find(0);         // 最终 0 所在集合的根

        for (int person = 0; person < n; person++) // 枚举所有人
        {
            if (uf.find(person) == root0) // 如果和 0 连通，说明知道秘密
            {
                ans.push_back(person);  // 加入答案
            }
        }

        return ans;                     // 返回结果
    }
};