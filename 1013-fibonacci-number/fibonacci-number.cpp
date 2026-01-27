class Solution {
public:
    int fib(int n) {
        if (n == 0)
          return 0;

        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n;  i++)
          dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
/*
    int fib(int n) {

        int step = 2;
        int fn  = 0;
        int fn0 = 0;
        int fn1 = 1;
        int fn2 = 0;

        if (n == 0)
          return fn0;
        else if (n == 1)
          return fn1;
 
        fn1 = fn1;
        fn2 = fn0;
        while (step <= n)
        {
            //fn1 = fn1;
            //fn2 = fn0;
            fn = fn1 + fn2;

            fn2 = fn1;
            fn1 = fn;

            step++;
                
        }

        return fn;
    } 

    */
};
