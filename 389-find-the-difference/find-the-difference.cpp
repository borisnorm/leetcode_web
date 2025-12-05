class Solution {
public:
    char findTheDifference(string s, string t) {
          int s_cnt[26];
          int t_cnt[26];

          for (auto& c: s)
            s_cnt[c-'a']++;
        
          for (auto& c: t)
            t_cnt[c-'a']++;
        
          for (int i = 0; i < 26; i++)
          {
             if (s_cnt[i] != t_cnt[i])
               return 'a' + i;
          }

          return ' ';
    }
};