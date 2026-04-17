class Solution {
public:
    int numOfWays(int n) {
        long long aba = 6;
        long long abc = 6;
        
        const int MOD = 1e9+7;

        for (int i = 1; i < n; i++)
        {
          long long nAba = (3 * aba + 2 * abc) % MOD;
          long long nAbc = (2 * aba + 2 * abc) % MOD;

          aba = nAba;
          abc = nAbc;
        }

        return (aba + abc) % MOD;
    }
};