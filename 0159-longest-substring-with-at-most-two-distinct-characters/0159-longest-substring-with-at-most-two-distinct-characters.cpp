class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty())
          return 0;
        int n = s.size();
        int l = 0;
        int r = 0;
        unordered_map<char, int> char2freq;
        
        int maxLen = INT_MIN;
        while (r < n)
        {
           char c = s[r];
           char2freq[c]++;
           r++;

           while(char2freq.size() > 2)
           {
              char d = s[l];
              char2freq[d]--;
              if (char2freq[d] == 0)
                char2freq.erase(d);
              l++;
           }

           maxLen = max(maxLen, r-l);
        }

        return maxLen;
        
    }
};