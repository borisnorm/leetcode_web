class Solution {
public:

/*  //这错误的, 返回的是 vector<n>  (0 <= i <= n)
   vector<int> countBits(int n) {
       int cnt = 0;

       while (n)
       {
          n = n & (n-1);
          cnt++;
       }

       return cnt;
   }
*/
   vector<int> countBits(int n) {
      vector<int> dp(n+1, 0);

      for (int i = 1; i <= n; i++)
        dp[i] = dp[i >> 1] + (i & 0x1); 

      return dp;
   }

    /*
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        //i & (i - 1) 把 i 变成了 比现在 最低位 少 1 的那个数了, 符合 dp 公式
        for (int i = 1; i <= n; i++)
           dp[i] = dp[(i & (i-1))] + 1;
        return dp;
    }
    */
};