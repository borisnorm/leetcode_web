class Solution {
public:
    string longestPalindrome(string s) {
        string res ="";
        for (int i = 0; i < s.size(); i++)
        {
           string s1 = palindrome(s, i, i);
           string s2 = palindrome(s, i, i+1);

           res = s1.size() > res.size() ? s1 : res;
           res = s2.size() > res.size() ? s2 : res;
        }

        return res;
    }

    string palindrome(string s, int l, int r)
    {
       // expand outside, but not shrink
       while (l >=0 && r < s.size() && l <= r && s[l] == s[r])
       {
          l--;
          r++;
       }

       return s.substr(l+1, r-l-1); // r-1 - (l + 1) + 1 = r - l - 1   
    }
};