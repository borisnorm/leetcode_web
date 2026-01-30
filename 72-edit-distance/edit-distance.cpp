class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int)word1.size();
        int n = (int)word2.size();

        // dp[i][j]: 最少的 convert 次数 from 以 word1[i-1] 结尾的 word1  to 以 words2[j-1] 结尾的 word2,
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // 当 dp 的 size 到达<= m 与 n 的时候 dp[m][n] 才能表示 word1的 word1[m-1] 与 word2的 word[n-1]
        for (int i = 1; i <= m; i++)
          //变成 j 的空串, 删除 以 i-1结尾的 应该有 i 个字符
          dp[i][0] = i;

        for (int j = 1; j <= n ; j++)
          //变成 j 的字符串, 添加 以 j-1 结尾的 应该有 j 个字符
          dp[0][j] = j;

        for (int i = 1; i <= m; i++)
        {
          for (int j = 1; j <= n; j++)
          {
              if (word1[i-1] == word2[j-1])
                //相同的情况下, 看前一个是否不同, 也就是不需要 额外的操作
                dp[i][j] = dp[i-1][j-1];
              else
                //covert type:
                //给 word1 +一个字母         dp[i][j-1]  给 word2 删除一个字符操作 实质上不等于 在 word1上添加一个字符, 但 次数却是相同的
                //给 word1 -一个字母         dp[i-1][j]  给 word1 删除一个字符
                //给 word1 replace 一个字母  dp[i-1][j-1]替换就是 先删除 word1 的 一个字符, 在给 word1添加一个字符 (等同于word2 删除的j-1)
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
          }
        }

        return dp[m][n];

    }
};