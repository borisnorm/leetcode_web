class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty())
          return 0;

        vector<int>  cnt(26, 0); 

        int ans = 0;

        int l = 0;
        int r = 0;
        int n = s.size();
        int maxcnt = 0;

        while (r < n)
        {
          int idx = s[r] - 'A';
          cnt[idx]++;
          
          r++;
          maxcnt = max(maxcnt, cnt[idx]);

          while ((r-l)-maxcnt > k)
          {
            int idx2 = s[l] - 'A';
            cnt[idx2]--;
            l++;
          }

          ans = max (ans, (r-l));
        }

        return ans;
    }
};