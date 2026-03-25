
class UnionFind
{
private:
    vector<int> p;      // p[x] 表示节点 x 的父节点
    vector<int> sz;     // sz[x] 表示以 x 为根的集合大小（仅根节点有效）

public:
    UnionFind(int n)
    {
        p.resize(n + 1);                    // 因为题目节点是 1-based，所以开到 n + 1
        sz.assign(n + 1, 1);                // 初始每个集合大小为 1
        iota(p.begin(), p.end(), 0);        // 初始化父节点，自己指向自己
    }

    int find(int x)
    {
        if (p[x] != x)                      // 如果 x 不是根
        {
            p[x] = find(p[x]);              // 路径压缩
        }
        return p[x];                        // 返回根节点
    }

    void unite(int a, int b)
    {
        int pa = find(a);                   // 找到 a 的根
        int pb = find(b);                   // 找到 b 的根

        if (pa == pb)                       // 如果已经在同一个集合中
        {
            return;                         // 直接返回
        }

        if (sz[pa] < sz[pb])                // 按大小合并，小树挂到大树上
        {
            swap(pa, pb);                   // 保证 pa 是更大的根
        }

        p[pb] = pa;                         // 把 pb 挂到 pa 上
        sz[pa] += sz[pb];                   // 更新集合大小
    }
};

class Solution
{
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries)
    {
        UnionFind uf(c);                                    // 创建并查集
        vector<int> ans;                                    // 存储所有 type-1 查询结果
        vector<bool> online(c + 1, true);                   // online[x] 表示 x 当前是否在线

        for (const auto& e : connections)                   // 遍历所有连接
        {
            int u = e[0];                                   // 连接的一个端点
            int v = e[1];                                   // 连接的另一个端点
            uf.unite(u, v);                                 // 合并这两个点所属集合
        }

        vector<set<int>> groups(c + 1);                     // groups[root] 存这个连通块里当前在线的所有点

        for (int i = 1; i <= c; ++i)                        // 遍历所有站点
        {
            int root = uf.find(i);                          // 找到 i 所属连通块根节点
            groups[root].insert(i);                         // 初始所有点都在线，加入对应 set
        }

        for (const auto& q : queries)                       // 按顺序处理所有查询
        {
            int type = q[0];                                // 查询类型
            int x = q[1];                                   // 查询涉及的站点

            int root = uf.find(x);                          // 找到 x 所属连通块根节点

            if (type == 1)                                  // 如果是查询操作
            {
                if (online[x])                              // 如果 x 当前在线
                {
                    ans.push_back(x);                       // 它自己处理，直接返回 x
                }
                else                                        // 如果 x 当前离线
                {
                    if (groups[root].empty())               // 如果整个连通块已经没有在线点
                    {
                        ans.push_back(-1);                  // 返回 -1
                    }
                    else                                    // 否则还有在线点
                    {
                        ans.push_back(*groups[root].begin()); // set 最小元素就是最小在线 id
                    }
                }
            }
            else                                            // 否则是 type == 2，下线操作
            {
                if (online[x])                              // 只有当前在线才需要处理
                {
                    online[x] = false;                      // 标记为离线
                    groups[root].erase(x);                  // 从所属连通块的在线集合中删掉
                }
            }
        }

        return ans;                                         // 返回所有 type-1 查询结果
    }
};