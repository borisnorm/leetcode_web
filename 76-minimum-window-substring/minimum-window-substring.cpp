class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        if (s.empty() || t.empty()) 
          return res;

        int m = s.size();
        int n = t.size();
        
         if (n > m)
           return "";
           
        unordered_map<char, int> need;
        unordered_map<char, int> window;
         // get t freq
         // slide window on s to match t
         // calculate len on matched case
         // return minLen
        for (char c : t)
          need[c]++;

        int l = 0;
        int r = 0;
        int valid = 0;
        int len = INT_MAX;
        int start = 0;

        while (r < m)
        {
            char c = s[r];  // [l, r)
            if (need.count(c))
            {
               window[c]++;
               if (window[c] == need[c])
                 valid++;
            }
            r++;

            while (valid == need.size())
            {
               if (r - l  < len)
               {
                 len = r - l;
                 start = l;
               }

               char d = s[l];
               if (need.count(d))
               {
                 if(window[d] == need[d])
                    valid--;
                  window[d]--;
               } 
               l++;
            }
        }
    
       return  len == INT_MAX ? "" : s.substr(start, len);
    }
};