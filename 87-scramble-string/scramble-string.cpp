class Solution {
public:
    
    string a, b;
    int m, n;
    int memo[31][31][31];
    bool isScramble(string s1, string s2) {
        m = s1.size();
        n = s2.size();
        if (m != n)
          return false;
        
        if (s1 == s2)
          return true;
        
        a = s1;
        b = s2;
        memset(memo, -1, sizeof(memo));

        return dfs(0, 0, m);
    }

    bool dfs(int i, int j, int len)
    {
       int& res = memo[i][j][len];

       if (res != -1)
         return res;
        
       //1. 子串完全相同, 直接返回 true
       if (a.compare(i, len, b, j, len) == 0)
       {
          res = 1;
          return true;
       }

       //2. 频率不同, 肯定 false
       int cnt[26] = {0};
       for (int k = 0; k < len; k++)
       {
         cnt[a[i+k]-'a']++;
         cnt[b[j+k]-'a']--;
       }

       for (int c = 0; c < 26; c++)
       {
          if (cnt[c] != 0)
          {
            res = 0;
            return false;
          }
       }

      //3. 枚举切分点
      for (int k = 1; k < len; k++)
      {
         if (dfs(i,j, k) && dfs(i+k, j+k, len-k))
         {
            res = 1;
            return true;
         }

         if (dfs(i, j + len - k, k) && dfs(i + k, j, len-k))
         {
            res = 1;
            return true;
         }
      }

    res = 0;
    return false;

    }
};