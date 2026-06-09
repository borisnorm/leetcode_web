class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        if (s.empty() || t.empty())
          return res;
        
        // target: minium window of s 
        //       m = s.size()

        int m = s.size();
        int n = t.size();

        /* freq window */
        int window[128] = {};
        int need[128] = {};
        int need_cnt = 0;
        
        for(char c: t)
        {
           if (need[c] == 0)
              need_cnt++;
           need[c]++;
        }

        int l = 0;
        int r = 0;
        int valid_cnt = 0;  // valid char cnt in s, which maps to t

        int start = 0;
        int len = INT_MAX;

        while (r < m)
        {
           char c = s[r];
           r++;

           if (need[c])
           {
              window[c]++;
              if (window[c] == need[c])
                valid_cnt++;
           }

           while(valid_cnt == need_cnt)
           {
               if (r - l < len)
               {
                  len = r - l;
                  start = l;
               }

               char d = s[l];
               l++;

               if (need[d])
               {
                  if (window[d] == need[d])
                    valid_cnt--;
                  window[d]--;
               }
           }
           
        }

        //  check if s cantains all the character of t
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};


/*
class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        if (s.empty() || t.empty())
          return res;
        
        // target: minium window of s 
        //       m = s.size()

        int m = s.size();
        int n = t.size();

        // freq window
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        
        for(char c: t)
           need[c]++;
        
        int l = 0;
        int r = 0;
        int valid_cnt = 0;  // valid char cnt in s, which maps to t
        int len = INT_MAX;
        int start = 0;

        while (r < m)
        {
           char c = s[r];
           r++;

           if (need.count(c))
           {
              window[c]++;
              if (window[c] == need[c])
                valid_cnt++;
           }

           while(valid_cnt == need.size())
           {
               if (r - l < len)
               {
                  len = r - l;
                  start = l;
               }

               char d = s[l];
               l++;

               if (need.count(d))
               {
                  if (window[d] == need[d])
                    valid_cnt--;
                  window[d]--;
               }
           }
           
        }

        //  check if s cantains all the character of t
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
*/
