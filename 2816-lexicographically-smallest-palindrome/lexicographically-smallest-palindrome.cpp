class Solution {
public:
    string makeSmallestPalindrome(string s) {
        
        int n = s.size();
        
        int l = 0;
        int r = n - 1;

        while (l < r)
        {
           if (s[l] != s[r])
           {
              char c = min(s[l], s[r]);
              s[l] = s[r] = c;
           }

           l++;
           r--;
        }

        return s;
    }
};