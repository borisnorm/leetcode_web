class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size())
          return res;
        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for (char c: p)
          need[c-'a']++;

        int left = 0;
        int right = 0;
        int valid = 0;

        while (right < s.size())
        {
          char c = s[right];
          right++;
          window[c-'a']++;

          if (window[c-'a'] == need[c-'a'])
            valid++;
          
          while (right-left > p.size())
          {
             char d = s[left];
             left++;
             if (window[d-'a'] == need[d-'a'])
               valid--;
             window[d-'a']--;
          }

          if (right-left == p.size() && window == need)
            res.push_back(left); 

        }

        return res;
    }

};