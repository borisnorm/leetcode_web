class Solution {
public:
    int climbStairs(int n) {
    
      if (n == 0 || n == 1)
         return 1;
       else if (n == 2)
         return 2;
       
       // answer on ways;

       vector<int> dp(n+1, 0);
       dp[0] = 1;
       dp[1] = 1;
       dp[2] = 2;

       for (int i = 3; i <= n; i++)
         dp[i] = dp[i-2] + dp[i-1];
    
       return dp[n];
    }
};