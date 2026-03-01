
class Solution
{
public:
    int minCut(string s)
    {
        if (s.empty())                                  // 如果是空串
        {
            return 0;                                   // 不需要切
        }

        int n = (int)s.size();                          // 字符串长度
        const int INF = 1000000000;                     // 无穷大
        vector<int> dp(n + 1, INF);                     // dp[i]：前 i 个字符最少回文段数(pieces)
        dp[0] = 0;                                      // 空前缀需要 0 段

        for (int c = 0; c < n; c++)                     // 关键：同一个 c 内同时做奇回文 + 偶回文
        {
            // ---------- 1) 奇数长度回文扩展：中心在 c ----------
            {
                int l = c;                              // 左指针从中心开始
                int r = c;                              // 右指针从中心开始
                while (l >= 0 && r < n && s[l] == s[r]) // 扩展条件：不越界且相等
                {
                    dp[r + 1] = min(dp[r + 1], dp[l] + 1); // s[l..r] 是回文 => dp[r+1] 可由 dp[l]+1 转移
                    l--;                                // 左扩
                    r++;                                // 右扩
                }
            }

            // ---------- 2) 偶数长度回文扩展：中心在 (c, c+1) ----------
            {
                int l = c;                              // 左中心
                int r = c + 1;                          // 右中心
                while (l >= 0 && r < n && s[l] == s[r]) // 扩展条件
                {
                    dp[r + 1] = min(dp[r + 1], dp[l] + 1); // s[l..r] 是回文 => 更新 dp[r+1]
                    l--;                                // 左扩
                    r++;                                // 右扩
                }
            }
        }

        return dp[n] - 1;                               // dp[n] 是段数 => cuts = 段数 - 1
    }
};

/*
class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();

        // isPalin[i][j]: s[i..j] 是否回文
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));

        // 区间DP预处理回文表
        // len=1: 单字符一定是回文
        // len=2: 两字符相等是回文
        // len>2: 两端相等且内部是回文
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j] && (j - i <= 1 || isPalin[i + 1][j - 1]))
                    isPalin[i][j] = true;
            }
        }

        // dp[i]: s[0..i] 的最少分割次数
        // 初始化为最坏情况：每个字符单独一段，切 i 次
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
            dp[i] = i; // 最多切 i 刀

        for (int i = 1; i < n; i++)
        {
            // 若 s[0..i] 整体是回文，0次分割
            if (isPalin[0][i])
            {
                dp[i] = 0;
                continue;
            }

            // 枚举最后一段 s[j..i]
            for (int j = 1; j <= i; j++)
            {
                if (isPalin[j][i])
                    dp[i] = min(dp[i], dp[j - 1] + 1); // 前段最优 + 1刀
            }
        }

        return dp[n - 1];
    }
};
*/
/*
class Solution {
public:
    int minCut(string s) {
        if (s.empty())
          return 0;
        int n = s.size();

        const int INF = 1e9;
        vector<int> dp(n+1, INF);
        dp[0] = 0;

        for (int c = 0; c < n; c++)
        {
           int l = c;
           int r = c;
           while (l >=0 && r < n && s[l] == s[r])
           {
              dp[r+1] = min(dp[r+1], dp[l]+1);
              l--;
              r++;
           }
        }
        
        for (int c = 0; c + 1 < n; c++)
        {
            int l = c;
            int r = c + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
               dp[r+1] = min(dp[r+1], dp[l] + 1);
               l--;
               r++;
            }
        }

        // dp[n] 是 最少回文段数, 切刀数 = 段数 - 1;
        return dp[n] - 1;
    }
};

*/