class Solution {
public:
    const int MOD = 1e9 + 7;
    
    bool validRow(int p)
    {
        int c0 = p / 9;
        int c1 = (p / 3) % 3;
        int c2 = p % 3;
        return c0 != c1 && c1 != c2;
    }

    bool compatible(int a, int b)
    {
      for (int i = 0; i < 3; i++)
      {
         if (a % 3 == b % 3)
           return false;
          
         a /= 3;
         b /= 3;
      }

      return true;

    }
    int numOfWays(int n) {
      vector<int> pats;
      // step 1:  枚举所有合法的 蛋黄, patter( 3^ 3 = 27种, 合法12 种)
      for (int p = 0; p < 27; p++)
      {
         if (validRow(p))
            pats.push_back(p);
      }

      int m = pats.size(); // m = 12;

      // step 2: 预处理兼容关系
      vector<vector<int>> compat(m);

      for (int i = 0; i < m; i++)
      {
         for (int j = 0; j < m; j++)
         {
            if (compatible(pats[i], pats[j]))
              compat[i].push_back(j);
         }
      }

      //step 3 初始化 dp
      vector<long long> dp(m, 1);

      //step 4 逐行转移
      for (int row = 1; row < n; row++)
      {
         vector<long long> ndp(m, 0);
         for (int i = 0; i < m; i++)
         {
            for (int j : compat[i])
               ndp[j] = (ndp[j] + dp[i]) % MOD;
         }

        dp = ndp;
      }

      long long ans = 0;
      for (auto x: dp)
        ans = (ans + x) % MOD;
      
      return ans;
      
    }
};

/*
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

*/