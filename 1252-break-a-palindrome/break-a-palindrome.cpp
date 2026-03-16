class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.size();
        if (n == 1)
          return "";
        
        for (int i = 0; i < n/2; i++)
        {
           //遇到的第一个 s[i]
           if (palindrome[i] != 'a')
           {
              palindrome[i] = 'a';
              return palindrome;
           }
        }

        // 字符串 全是'a', 改变最后一个字符就可以了
        palindrome[n-1] = 'b';
        return palindrome;
    }
};