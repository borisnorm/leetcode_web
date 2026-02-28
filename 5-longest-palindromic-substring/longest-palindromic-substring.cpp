
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
          return "";
        
        int n = s.size();

        int len = 0;
        int maxLen = INT_MIN;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
           // odd number
           int len1 = expand(s, i, i);
           // even number
           int len2 = expand(s, i, i+1);
        
           len = max(len1, len2);
           if (len > maxLen)
           {
              maxLen = len;
              // i               → 回文中心位置（奇数）或左中心位置（偶数）
              // len             → 回文的总长度
              // (len - 1)       → 从起点到终点的总跳数
              // (len - 1) / 2   → 从起点到中心的跳数（左侧跳数）
              // i - 左侧跳数     → 从中心向左跳，得到起点
              start  = i - (len -1) / 2;
              // 6  7/2 = 3 (0, 1, [2, 3], 4, 5) i = 2 
              // 5  6/2 = 3 (0, 1, [2], 3, 4)  i = 2
              //start = i - (len+1)/2 + 1;
           }
        }

        return s.substr(start, maxLen);
    }

    int expand(string& s, int l, int r)
    {
        int n = s.size();
        while (l >= 0 && r < n && s[l] == s[r])
        {
           l--;
           r++;
        }

        // 退出时 l 先--, r 先++了
        // [l+1, r-1]
        // len = (r-1) - (l+1) +1 = r - l - 1
        return r - l -1;
    }
};
/*
class Solution {
public:
    string longestPalindrome(string s) {
        string res ="";
        for (int i = 0; i < s.size(); i++)
        {
             // 情况1: 奇数长度回文，以i为中心
           string s1 = palindrome(s, i, i);
            // 情况2: 偶数长度回文，以i和i+1为中心
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


*/