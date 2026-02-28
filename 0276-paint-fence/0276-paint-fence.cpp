class Solution {
public:
    int numWays(int n, int k) {
        if (n <= 1)
          return k;
        
        //2ä¸ªçè¯ å¯ä»¥é åä¸é¢è², æä»¥ä¸æ¯ k * (k-1)
        if (n == 2)
          return k * k;

        // prev1 : last 2 diff: dp[i-1] * (k-1)    // 1 3 (2, 1, 3) -->k
        // prev2:  last 2 same: dp[i-2] *(k-1)     // 1, 1 (2, 3)  --> k-1
        int prev2 = k;
        int prev1 = k * k;
        for (int i = 3; i <= n; i++)
        {
           
           int prev = prev1 * (k-1) + prev2 * (k-1); 

           prev2 = prev1;
           prev1 = prev;
        }
        return prev1;
    }
};