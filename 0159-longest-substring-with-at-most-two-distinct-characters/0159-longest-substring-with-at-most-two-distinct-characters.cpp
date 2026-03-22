class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty())
          return 0;
        int n = s.size();
        int l = 0;
        int r = 0;
        int char2freq[128];
        
        int maxLen = INT_MIN;
        while (r < n)
        {
           char c = s[r];
           char2freq[c]++;
           r++;
           
           int distinctCharCnt = 0;
           for (int i = 0; i < 128; i++)
             if (char2freq[i] != 0)
               distinctCharCnt++;
            
           while(distinctCharCnt > 2)
           {
              char d = s[l];
              char2freq[d]--;
              if (char2freq[d] == 0)
                distinctCharCnt --;
              l++;
           }
           maxLen = max(maxLen, r-l);
        }
        return maxLen;
    }
};