class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();
        
        if (s_length != t_length)
          return false;
        
        if (!s_length)
          return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
       
        for (int i = 0; i < s_length; i++)
          if (s[i] != t[i])
            return false;

        return true;
    }
};