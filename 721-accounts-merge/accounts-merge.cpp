class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        //路径压缩
        if (parent[x] != x)
          parent[x] = find(parent[x]);
        
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry)
          return false;
        
        if (rank[rx] > rank[ry])
        {
           parent[ry] = rx;
        }
        else if (rank[rx] < rank[ry])
        {
           parent[rx] = ry;
        }
        else
        {
           parent[rx] = ry;
           rank[ry]++;
        }

        return true;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int>    email2id;        // email->id
        unordered_map<string, string> email2name;  // email->name
        int idx = 0;

        //[name, email-1, email-2, email-3, email-4]
        for (auto& acc : accounts)
        {
           const string& name = acc[0];
           for (int i = 1; i < (int)acc.size(); i++)
           {
             const string& email = acc[i];
             if (!email2id.count(email))
             {
                email2id[email]   = idx++;
                email2name[email] = name;
             }
           }
        }

       int n = idx;
       parent.assign(n, 0);
       for (int i = 0; i < n; i++)
         parent[i] = i;
       rank.assign(n, 0);

        for (auto& acc: accounts)
        {
          if (acc.size() < 2)  // 0.name, 1.only email,  --> not necessary for union
            continue;
          int base = email2id[acc[1]];
          for (int i=2; i < (int)acc.size(); i++)
            unite(base, email2id[acc[i]]);
        }

        unordered_map<int, vector<string>> groups;
        for (auto& kv : email2id)
        {
          const string& email = kv.first; // email
          int   root = find(kv.second);   // find id
          groups[root].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto& g: groups)
        {
            auto& emails = g.second;
            sort(emails.begin(), emails.end());
            emails.erase(unique(emails.begin(), emails.end()), emails.end());
            string name = email2name[emails[0]];

            vector<string> row;
            row.push_back(name);
            row.insert(row.end(), emails.begin(), emails.end());
            ans.push_back(move(row));
        }

        return ans;
        
    }
};


/*
class UnionFind
{
public:
    unordered_map<string, string> parent;    // p[x] 表示节点 x 的父节点
    unordered_map<string, int> rank;       // r[x] 表示节点 x 的秩（近似树高）

    void add(const string& x)           // 如果节点不存在，则初始化它
    {
        if (!parent.count(x))                // 如果 x 还没有出现过
        {
            parent[x] = x;                   // 初始时父节点指向自己
            rank[x] = 0;                   // 初始秩为 0
        }
    }

    string find(const string& x)        // 查找 x 的根节点，并做路径压缩
    {
        if (parent[x] != x)                  // 如果 x 不是根节点
        {
            parent[x] = find(parent[x]);          // 递归找到根，并直接挂到根上
        }
        return parent[x];                    // 返回最终根节点
    }

    void unite(const string& a, const string& b)   // 合并 a 和 b 所在集合
    {
        string ra = find(a);            // 找到 a 的根
        string rb = find(b);            // 找到 b 的根

        if (ra == rb)                   // 如果已经在同一集合中
            return;                     // 直接返回

        if (rank[ra] < rank[rb])              // 如果 a 的树更矮
            parent[ra] = rb;                 // 把 a 的根挂到 b 的根下面
        else if (rank[ra] > rank[rb])         // 如果 b 的树更矮
            parent[rb] = ra;                 // 把 b 的根挂到 a 的根下面
        else                            // 如果两棵树高度相同
        {
            parent[rb] = ra;                 // 随便挂一个，这里把 rb 挂到 ra
            rank[ra]++;                    // ra 的秩加 1
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        UnionFind uf;                                       // 创建并查集对象
        unordered_map<string, string> email2Name;          // 记录 email -> name

        // email -> name
        // uf.add email as union-find set
        // unite(firstEmail, otherEmail)
        for (const auto& acc : accounts)                    // 遍历每个账户
        {
            const string& name       = acc[0];              // 账户名
            const string& firstEmail = acc[1];              // 该账户的第一个 email

            uf.add(firstEmail);                             // 确保第一个 email 在并查集中
            email2Name[firstEmail] = name;                 // 记录该 email 对应的 name

            for (int i = 2; i < (int)acc.size(); i++)       // 遍历该账户剩余 email
            {
                const string& email = acc[i];               // 当前 email
                uf.add(email);                              // 确保当前 email 在并查集中
                email2Name[email] = name;                  // 记录当前 email 对应的 name

                uf.unite(firstEmail, email);                // 把当前 email 和第一个 email 合并
            }
        }

        // build root(email)->email_group from email2Name
        unordered_map<string, vector<string>> groups;       // root -> 所有属于该组的 emails

        for (const auto& [email, name] : email2Name)       // 遍历所有出现过的 email
        {
            string root = uf.find(email);                   // 找到该 email 的最终根节点
            groups[root].push_back(email);                  // 放入对应分组
        }

        vector<vector<string>> res;                         // 最终结果数组
        // go through root-groups
        for (auto& [root, emails] : groups)                 // 遍历每个分组
        {
            sort(emails.begin(), emails.end());             // 题目要求按字典序排序 email

            //build email vector
            vector<string> cur;                             // 当前合并后的账户
            cur.push_back(email2Name[root]);                // 先放名字，root 对应 email 一定能找到名字
            for (const string& email : emails)              // 再把排序后的 emails 放进去
                cur.push_back(email);                       // 加入当前结果

            res.push_back(cur);                             // 放入总结果
        }

        return res;                                         // 返回最终答案
    }
};
*/

/*
class Solution {
public:
    struct DSU{
        vector<int> parent;
        vector<int> rank;

        DSU(){}
        DSU(int n){init(n);}

        void init(int n)
        {
          parent.resize(n);
          sizev.assign(n, 1);
          iota(parent.begin(), parent.end(), 0);
        }

        int find(int x)
        {
          if (parent[x] != x)
            parent[x] = find(parent[x]);
          return parent[x];
        }

        void unite(int x, int y)
        {
          int rx = find(x);
          int ry = find(y);
          if (rx == ry)
            return;
          if (sizev[rx] < sizev[ry])
            swap(rx, ry);
          parent[ry] = rx;
          sizev[rx] += sizev[ry];
        }
    };


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> id;        // email->id
        unordered_map<string, string> owner;  // email->name
        int idx = 0;

        for (auto& acc : accounts)
        {
           const string& name = acc[0];
           for (int i = 1; i < (int)acc.size(); i++)
           {
             const string& email = acc[i];
             if (!id.count(email))
             {
                id[email] = idx++;
                owner[email] = name;
             }
           }
        }

        DSU dsu(idx);

        for (auto& acc: accounts)
        {
          if (acc.size() < 2)  // 0.name, 1.only email,  --> not necessary for union
            continue;
          int base = id[acc[1]];
          for (int i=2; i < (int)acc.size(); i++)
            dsu.unite(base, id[acc[i]]);
        }

        unordered_map<int, vector<string>> groups;
        for (auto& kv : id)
        {
          const string& email = kv.first;
          int root = dsu.find(kv.second);
          groups[root].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto& g: groups)
        {
            auto& emails = g.second;
            sort(emails.begin(), emails.end());
            emails.erase(unique(emails.begin(), emails.end()), emails.end());
            string name = owner[emails[0]];

            vector<string> row;
            row.push_back(name);
            row.insert(row.end(), emails.begin(), emails.end());
            ans.push_back(move(row));
        }

        return ans;
        
    }
};

*/