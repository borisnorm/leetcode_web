class Solution {
public:
    int jump(vector<int>& nums) {
         int n = nums.size();
         if (n <= 1)
           return 0;
        
         //防止 dp[i] + 1 溢出
         // 错误书写
         //const int INF INT_MAX/2;
         const int INF = INT_MAX/2;
         vector<int> dp(n, INF);
         dp[0] = 0;

         for (int j = 1; j < n; j++)
         {
            for (int  i = 0; i < j; i++)
            {
               if (j > i + nums[i])
                 continue;
              // if (dp[i] == INT_MAX)
               //  continue;
               dp[j] = min(dp[j], dp[i]+1);
            }
         }

         return dp[n-1];
    }
};
/*
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) 
           return 0;

        int steps = 0;
        int curEnd = 0;   // 当前跳跃次数 steps 能覆盖到的最右边界
        int farthest = 0;   // 在 [0..end] 扫描过程中，下一跳能到的最远位置

        // 注意：遍历到 n-2 还能向前跳，因为到达/越过 n-1 就结束，不需要在最后一个位置再“起跳”
        // n 个节点 , 需要 n-1跳
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            // 走到当前层的边界：必须增加一次跳跃，进入下一层
            // far 是 [preEnd+1, curEnd] 这个距离种所累计的 最远跳数
            if (i == curEnd) {
                steps++;
                curEnd = farthest;

                // 当前层扩展后已覆盖终点
                // 如果 当前 range 的最远距离已经覆盖了 n-1, 
                // 那么 可以直接 break了, step 已经++了,直接跳过去就可以了
                if (curEnd >= n - 1) 
                  break;
            }
        }
        return steps;
    }
};
*/

/*
class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int pos = 0;
        int rol = 0;
        int col = 0;
        int jumps = 0;

        for (i = 0; i < nums[pos]; i++)
          sum += nums[pos];

        vector<vector<int>> steps(sum, vector<int>(nums.size(), INT_MIN));
        
        jump_i(nums, steps, jumps, rol, col);

        int sum_jump;
        int min_steps = 0;
        for (i = 0; i < sum; i++)
        {
          j = nums[i];
          for (j = 0; j < nums.size(); j++)
          {
            if (steps[i][j] == INT_MIN)
              break;
            else
              sum_jump += steps[i][j];
          }
          
          min_steps = min(min_steps, sum_jump);
        }
       
        return min_steps;
    }

    int jump_i(vector<int>& nums, vector<vector<int>>& steps, int jumps, int rol, int col)
    {
        if (col == (nums.size() - 1))
        {
          fill(steps[rol].begin(), steps[rol].end(), 0);
          steps[rol][col]=jumps;
          return 1;
        }
        else if (col > (nums.size() - 1))
          return -1;
     
        int i;
        int res = 0;
        int pos = col;
        int col2;
        int rol2;
        for (i = 0; i < nums[pos]; i++)
        {
          col2 = col + i; 
          rol2 = rol + 1;
          jumps = i;
          
          res = jump_i(nums, steps, jumps, rol2, col2);
          if (res)
            steps[rol][col]=jumps;   
        }
        return jump_i(nums, steps, jumps, (rol2 + 1), col2);
    }
};
*/