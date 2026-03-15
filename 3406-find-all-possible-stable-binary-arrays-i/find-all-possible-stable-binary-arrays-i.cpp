class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        long long const MOD = 1000000007;
        // 以 0 结尾的 zero 个0, one 个 1
        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        // 以 1 结尾的 zero 个0, one 个 1
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));
      
        for (int i = 0; i <= min(zero, limit); i++)
          dp0[i][0] = 1;

        for (int j = 0; j <= min(one, limit); j++)
          dp1[0][j] = 1;

        for (int i = 1; i <= zero; i++)
        {
          for (int j = 1; j <= one; j++)
          {
             for (int k = 1; k <= min(i, limit); k++)
               // dp1 表示前段是 1 的 case, 但1的个数是 < limit 的
               dp0[i][j] = (dp0[i][j] + dp1[i-k][j]) % MOD;

             for (int k = 1; k <= min(j, limit); k++)
               dp1[i][j] = (dp1[i][j] + dp0[i][j-k]) % MOD;
          }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};