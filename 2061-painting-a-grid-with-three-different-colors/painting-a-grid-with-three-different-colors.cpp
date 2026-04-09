class Solution {
public:
    const int MOD = 1e9+7;
    // 检查单列状态 s 是否合法
    bool validCol(int s, int m)
    {
       for (int i = 0; i < m - 1; i++)
       {
          //取 i 行 与  i+1 行的 颜色 (3 进制)
           if ((s/(int)pow(3, i) % 3) == (s/(int)pow(3, i + 1) % 3))
             return false;
       }

       return true;
    }

    bool compat(int s, int t, int m)
    {
      for (int i = 0; i < m; i++)
      {
        if ((s / (int)pow(3, i) % 3) == (t/(int)pow(3, i) % 3))
          return false;
      }

      return true;
    }
    int colorTheGrid(int m, int n) {
       vector<int> valid;
       int total = 1;
       for (int i = 0; i < m; i++)
         total *= 3;

       for (int s = 0; s < total; s++)
       {
          if (validCol(s, m))
            valid.push_back(s);
       }

       int sz = valid.size();

       vector<vector<int>> adj(sz);
       for (int i = 0; i < sz; i++)
       {
          for (int j = 0; j < sz; j++)
            if (compat(valid[i], valid[j], m))
              adj[i].push_back(j);
       }

       vector<long long> dp(sz, 1);

       for(int col = 1; col < n; col++)
       {
          vector<long long> ndp(sz, 0);
          for (int i = 0; i < sz; i++)
          {
              for (int j : adj[i])
              {
                  ndp[i] = (ndp[i] + dp[j]) % MOD;
              }
          }
          dp = ndp;
       }

       long long ans = 0;
       for (auto x: dp)
         ans = (ans + x) % MOD;
      
       return ans;
    }
};