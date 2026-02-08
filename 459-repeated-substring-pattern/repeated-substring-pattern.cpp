class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        if (s.empty())
          return true;

        int n = s.size();
        if (n == 1)
          return false;
        
        vector<int> lps(n, 0);
        
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            //int j = lps[i-1];

            while (j > 0 && s[i] != s[j])
              j = lps[j-1];

            if (s[i] == s[j])
              j++;

            lps[i] = j;
        }

        int l = lps[n-1];
        return (l > 0 && (n %(n-l) == 0)) ? true: false;
    }
};

/*
class Solution {
public:

    bool repeatedSubstringPattern(string s) {
         string t = s + s;
        
         int t_sz = t.size();

         //multiple copies of the substring 
         //意思是  这字符串至少由 2个以上的 重复 substr 组成
         // n - 1 | n - 1;
         // 重新 再连接一个 s 后, 就是
         //  n - 1 | [n - 1 | n - 1] | n - 1;
         // 中间的两个必然重复
         // 去掉头尾, 找 rotated substring pattern
         string rotated_substr = t.substr(1, t_sz - 2);

         if (rotated_substr.find(s) != string::npos)
           return true;
        
        return false;
    }
};
*/