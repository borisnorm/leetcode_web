class Solution {
public:
    struct UnionFind
    {
        vector<int> parent;

        UnionFind(int n)
        {
            parent.assign(n, 0);
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
            parent[find(x)] = find(y);
        }
    };

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
        sort(meetings.begin(), meetings.end(),
             [](auto& a, auto& b)
             {
                 return a[2] < b[2];
             });

        UnionFind uf(n);

        uf.unite(0, firstPerson);

        int i = 0;
        int m = meetings.size();

        while (i < m)
        {
            int j = i;
            int t = meetings[i][2];

            while (j < m && meetings[j][2] == t)
                j++;

            unordered_set<int> ppl;

            for (int k = i; k < j; k++)
            {
                int x = meetings[k][0];
                int y = meetings[k][1];

                uf.unite(x, y);
                ppl.insert(x);
                ppl.insert(y);
            }

            for (int person : ppl)
            {
                if (uf.find(person) != uf.find(0))
                    uf.parent[person] = person;
            }

            i = j;
        }

        vector<int> ans;

        for (int person = 0; person < n; person++)
        {
            if (uf.find(person) == uf.find(0))
                ans.push_back(person);
        }

        return ans;
    }
};