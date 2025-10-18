class Solution {
public:
    int numDecodings(string s) {
        // a(1) --z (26) -- A(27)   27 - 1 = 26 - 26 + 1
        // 'A'-'a'-26 +   

        if (s.empty())
          return 0;
        int n = s.size();

        // [i-1] + c  ,  1 < c < 9    c[i-1]
        // [i-2] + d ,  d <=2 && 2 < c < 6   d[i-1]

        vector<int> dp(n+1, 0);
        int ans = 0;
 
        dp[0] = 1;
        dp[1] = (s[0] != '0') ? 1 : 0; 

        for (int i = 2; i <= n ; i++)
        {
            char c = s[i-1];
            char d = s[i-2];

            if ('1' <= c && c <= '9')
              dp[i]+= dp[i-1];

           if (d == '1' || d == '2' && c <= '6')
              dp[i]+= dp[i-2];
        }

        return dp[n];
    }
};