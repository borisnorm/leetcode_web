class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int k = primes.size();
        vector<int> dp(n+1, 1);
        vector<int> nxtDp(k, 1);

        for (int i = 2; i <= n; i++)
        {
           long long minDp = INT_MAX;
           for (int j = 0; j < k; j++)
           {
              minDp = min(minDp, (long long)dp[nxtDp[j]] * primes[j]);
           }

           dp[i] = minDp;

           for (int j = 0 ; j < k; j++)
           {
              if ((long long)dp[nxtDp[j]] * primes[j] == minDp)
              {
                  nxtDp[j]++;
              }

           }
        }

        return dp[n];
    }
};