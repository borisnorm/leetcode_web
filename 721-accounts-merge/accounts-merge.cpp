class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
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

       int n = idx;
       parent.assign(n, 0);
       for (int i = 0; i < n; i++)
         parent[i] = i;
       rank.assign(n, 0);

        for (auto& acc: accounts)
        {
          if (acc.size() < 2)  // 0.name, 1.only email,  --> not necessary for union
            continue;
          int base = id[acc[1]];
          for (int i=2; i < (int)acc.size(); i++)
            unite(base, id[acc[i]]);
        }

        unordered_map<int, vector<string>> groups;
        for (auto& kv : id)
        {
          const string& email = kv.first;
          int root = find(kv.second);
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