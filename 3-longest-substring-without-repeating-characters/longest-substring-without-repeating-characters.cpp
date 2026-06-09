class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
          return 0;
        
        unordered_map<char, int> char2freq;
        
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxLen = 0;

        while (r < n)
        {
           char c = s[r];
           char2freq[c]++;
           r++;

           while (char2freq[c] > 1)
           {
              char d = s[l];
              char2freq[d]--;
              if (char2freq[d] == 0)
                char2freq.erase(d);
              l++;
           }

           maxLen = max(maxLen, r - l);
        }

        return maxLen;
    }
};