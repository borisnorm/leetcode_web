class Solution {
public:
    //Manacher 解法 O(n) O(n) 
    string longestPalindrome(string s) {

       string head = "^"; // sanitel
       string tail = "$";

       string t = head;

       t += "#";
       //原字符串长度: n
       //预处理后长度: 2n + 1  (永远是奇数!)
       for (char c: s)
       {
           t += c;
           t += '#';
       }
       t += tail;

       int n = t.size();
       //p[i] = 以i为中心的最大半径
       // p[i] = k 的含义:
       // 1. 中心位置: i
       // 2. 回文半径: k
       // 3. 回文范围: [i-k, i+k]
       // 4. 回文长度: 2k+1 (预处理串中)
       // 5. 原串长度: k (去掉'#'后)

       vector<int> p(n, 0);

       int center = 0;
       int right = 0;

       int maxRadius = 0;     //当前正在计算的位置（循环变量）
       int maxCenter = 0;  //目前为止最右回文的中心

       for (int i = 1; i < n-1; i++)
       {
          // i在 center 的 右边
           // i - center = center - mirror
          
          //### 为什么 mirror 总是在 i 前面？

         // 因为: i > center  (i在center右侧，还在往右遍历)
         // 所以: mirror = 2*center - i < 2*center - center = center < i
         // 结论: mirror < center < i
         // ↑已算过    ↑已算过  ↑正在算
         // mirror一定在i左边，所以p[mirror]一定已经计算过了
          int mirror = 2 * center - i;

          // 因为对称性只在[left, right]内有效！
          // 如果 p[mirror] 大, 需要 right - i 来进行限制
          if (i < right)
            p[i] = min(right - i, p[mirror]);
        
          // 要扩展: 需要检查下一个位置
           // 左边下一个: i-p[i]-1
          // 右边下一个: i+p[i]+1
           while(t[i-p[i]-1] == t[i+p[i]+1])
             p[i]++;
        
          if (i + p[i] > right)
          { 
            center = i;  //注意 center 也被更新了, left 没有使用也没有被更新
            right = i + p[i];
          }

          if (p[i] > maxRadius)
          {
             maxRadius = p[i];
             maxCenter = i;
          }
       }

      //  原串索引i → 预处理串索引 2*(i+1)

     // 原串索引0 → 预处理串索引2 
     //原串索引1 → 预处理串索引4
      // 原串索引2 → 预处理串索引6

        // 反推公式:
       //预处理串索引j (偶数) → 原串索引 j/2 - 1
       // 切换到 原索引上去
       //整数除法自动向下取整，正好对应起始位置
       // 2 就是消除 # 的影响
       int start = (maxCenter - maxRadius) / 2;

       //p[i]表示的是t（预处理串）的半径, 但却是 s的长度, t 的半径就是 s 的整体长度 
       //maxLen正好等于原串s的长度！
       return s.substr(start, maxRadius);
    }
};


/*
 // 时间 O(n^2) 空间 O(1)
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
              // i               → 回文中心位置（奇数）或 左 中心位置（偶数）
              // len             → 回文的总长度
              // (len - 1)       → 从起点到终点的总跳数
              // (len - 1) / 2   → 从起点到中心的跳数（左侧跳数）
              // i - 左侧跳数     → 从中心向左跳，得到起点
              // len = 6  (6-1)/2 = 2  (0, 1, [2, 3], 4, 5) i = 2 
              // len = 5  (5-1)/2 = 2  (0, 1, [2], 3, 4)  i = 2
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