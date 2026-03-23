class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));

        // dp[m-1+1][n-1]
        // dp[m-1][n-1+1]
        dp[m][n-1] = 1;
        dp[m-1][n] = 1;

        for (int i = m-1; i >= 0; i--)
        {
          for (int j = n-1; j >= 0; j--)
          {
             int need = min(dp[i+1][j], dp[i][j+1]);
            
            //dp[i][j] 的语义
            // 还没进入 (i,j)，站在门口，问：我至少要带多少血，才能进去、经过这格、然后活着走到终点？
            //离开时，你要进入下一格，下一格要求你至少带 need 血：
            // dp[i][j] + dun[i][j] >= need
            //
            //站在门口        进入格子          离开格子
            // 带着 dp[i][j]  →  +dun[i][j]  →  剩余血量 = dp[i][j] + dun[i][j]
            // dp[i][j] 是进门前的最低血量要求。
            // need 是出门后的最低血量要求。
            // dun[i][j] 是进入该格后血量的变化值
            // 负数：扣血（恶魔房间）
            // 正数：加血（魔法药水） 
            // dp[i][j] + dungeon[i][j] >= need;
             dp[i][j] = max(1, need-dungeon[i][j]);
          }
        }

        return dp[0][0];
    }
};