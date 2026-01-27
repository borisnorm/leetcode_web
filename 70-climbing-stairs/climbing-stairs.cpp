class Solution {
public:
    int climbStairs(int n) {
        if (n < 0)
          return 0;
        else if (n == 0 || n == 1 )
          return 1;
        else if (n == 2)
          return 2;
        
        int prev1 = 1;  //dp[i-1]  1 way 
        int prev2 = 1;  //dp[i-2]  two ways on 2 steps diff
        int prev = 0;

        for (int i = 2; i <=n; i++)
        {
           prev = prev1 + prev2;
           prev2 = prev1;
           prev1 = prev;
        }

        return prev;
    }
    
  /*
    int climbStairs(int n) {
    
      if (n == 0 || n == 1)
         return 1;
       else if (n == 2)
         return 2;
       
       // answer on ways;
       vector<int> dp(n+1, 0);
       dp[0] = 1;
       dp[1] = 1;

       for (int i = 2; i <= n; i++)
         dp[i] = dp[i-2] + dp[i-1];
    
       return dp[n];
    }
    */
};


