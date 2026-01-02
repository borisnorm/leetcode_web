class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int i = 0;
        int j = 0;
        int res = 0;

        int n = s.size();
        int m = g.size();

        while (i < n && j < m)
        {
            if (s[i] >= g[j])
            {
               res++;
               i++;
               j++;
            }
            else
            {
               i++;
            }
        }

        return res;
    }
};