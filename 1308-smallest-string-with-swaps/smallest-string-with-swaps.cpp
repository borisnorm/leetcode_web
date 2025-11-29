class Solution {
    vector<int> parent;
    vector<int> rank;

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

        if (rank[rx] < rank[ry])
        {
            parent[rx] = parent[ry];
        }
        else if (rank[rx] > rank[ry])
        {
           parent[ry] = parent[rx];
        }
        else
        {
            parent[rx] = parent[ry];
            rank[ry]++;
        }


    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        if ( n == 0 || pairs.empty())
          return s;

        parent.assign(n, 0);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
          parent[i] = i;

        for(const auto &p : pairs)
        {
           int a = p[0];
           int b = p[1];
           unite(a, b);
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++)
        {
            int root = find(i);
            groups[root].push_back(i);
        }


        for (auto &kv : groups)
        {
            auto& idxs = kv.second;
            string chars;

            for (int idx: idxs)
              chars.push_back(s[idx]);

            sort(idxs.begin(), idxs.end());
            sort(chars.begin(), chars.end());

            for (int k = 0; k < idxs.size(); k++)
              s[idxs[k]] = chars[k];
        }

        return s;
    }

};