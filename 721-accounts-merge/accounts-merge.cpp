class Solution {
public:
    struct DSU{
        vector<int> parent;
        vector<int> sizev;

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