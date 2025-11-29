class Solution {
public:
    int countBinarySubstrings(string s) {
        
        if (s.empty())
          return 0;

        int prevLen = 0;
        int curLen = 1;
        int ans = 0;

        int n = s.size();
        for (int i = 1; i < n; i++)
        {
           if (s[i] == s[i-1])
             curLen++;
           else
           {
              ans += min(prevLen, curLen);
              prevLen = curLen;
              curLen = 1;
           }
        }

        ans += min(curLen, prevLen);

        return ans;
    }
};