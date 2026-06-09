class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        int n = s.size(); //string
        int m = p.size(); //pattern
        if (n < m)
          return res;
        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for (char c: p)
          need[c-'a']++;

        int left = 0;
        int right = 0;
        int valid_cnt = 0;

        while (right < n)
        {
          char c = s[right];
          right++;
          window[c-'a']++;

          if (window[c-'a'] == need[c-'a'])
            valid_cnt++;
          
          while (right-left > p.size())
          {
             char d = s[left];
             left++;
             if (window[d-'a'] == need[d-'a'])
               valid_cnt--;
             window[d-'a']--;
          }

          if (right-left == m && window == need)
            res.push_back(left); 

        }

        return res;
    }

};