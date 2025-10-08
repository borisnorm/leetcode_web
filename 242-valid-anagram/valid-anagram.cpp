class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();
        
        if (s_length != t_length)
          return false;
        
        if (!s_length)
          return false;

        vector<int> count(26,0);

        for (int i = 0; i < s_length; i++)
        {
          count[s[i]-'a']++;
          count[t[i]-'a']--;
        }

        for (auto c: count)
          if (c)
            return false;
        
        return true;
    }
};