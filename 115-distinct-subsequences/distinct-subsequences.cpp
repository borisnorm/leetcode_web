class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();

        int n = t.size();

        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long>(n+1, 0));
         
         // dp[i][j]   以s[i-1]结尾的 子序列 中 等于 t 的[j-1]的个数
        
        for (int i = 0; i <= m; i++)
          dp[i][0] = 1;

        for (int i = 1; i <= m; i++)
        {
           for (int j = 1; j <= n; j++)
           {
              // dp[i-1][j] 表示删除 s 的第 i-1个字符后 剩下的字符与 t 进行比较
              if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
              else
                dp[i][j] = dp[i-1][j];
                
           }
        } 

       return (int)dp[m][n];
    }
};