class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //p is the pattern
        
        vector<int> res;
        int n = s.size();
        int m = p.size();

        if (n < m)
          return res;
        
        vector<int> need(26, 0);
        vector<int> window(26, 0);
        
        for (char c: p)
          need[c-'a']++;

        int l = 0;
        int r = 0;

        while (r < n)
        {
           char c = s[r];
           window[c-'a']++;
           r++;

           while(r-l > m)
           {
              char d = s[l];
              window[d-'a']--;
              l++;
           }

           if (window == need)
             res.push_back(l);
        }

        return res;
    }
};