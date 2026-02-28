class Solution {
public:
    string longestPalindrome(string s) {
       string t = "#";
       
       //原字符串长度: n
       //预处理后长度: 2n + 1  (永远是奇数!)
       for (char c: s)
       {
           t += c;
           t += '#';
       }

       int n = t.size();
       //p[i] = 以i为中心的最大半径
       vector<int> p(n, 0);

       int center = 0;
       int right = 0;

       int maxLen = 0;
       int maxCenter = 0;

       for (int i = 0; i < n; i++)
       {
          int mirror = 2 * center - i;

          if (i < right)
            p[i] = min(right - i, p[mirror]);
        
           
           while(i - p[i] - 1 >= 0 && i + p[i] + 1 < n && 
                t[i-p[i]-1] == t[i+p[i]+1])
              p[i]++;
        
          if (i + p[i] > right)
          { 
            center = i;
            right = i + p[i];
          }

          if (p[i] > maxLen)
          {
             maxLen = p[i];
             maxCenter = i;
          }
       }

       int start = (maxCenter - maxLen) / 2;
       return s.substr(start, maxLen);
    }
};


/*
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
          return "";

        // Time: O(n^2) 
        // Space: O(1)       
        int n = s.size();

        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
           // odd number
           int len1 = expand(s, i, i);
           // even number
           int len2 = expand(s, i, i+1);
        
           int len = max(len1, len2);
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
        return r - l - 1;
    }
};
*/
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