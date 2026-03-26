class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
          
          vector<int> prereq(n, 0);
          
          for (auto& edge: relations)
          {
              int pre = edge[0] - 1;
              int course = edge[1] - 1;

              prereq[course] |= (1 << pre);
          }

          // total courses Mask, 1111111111那种
          int total = (1 << n) - 1;

          //dp[mask] 已经修完的课程集合
          vector<int> dp(total+1, INT_MAX);
          dp[0] = 0;

         
          // mask 在模拟 哪些课程已经完成了
          for (int mask = 0; mask <= total; mask++)
          {
             int canTake = 0;
             if (dp[mask] == INT_MAX)
               continue;
            
             //遍历所有课程
             for (int i = 0; i < n; i++)
             {
                // mask 向右移动 跳转到相应的课程上去
                // 若是上过的课, 跳过
                if ((mask >> i) & 1)
                  continue;

                //第 i 门课程 的所有 prerequisite 都完成了吗
                if ((mask & prereq[i]) == prereq[i])
                  canTake |= (1 << i);  // 可以上 第 i 门课了
             }

            int cnt = __builtin_popcount(canTake);

            if (cnt <= k)
            {
               int nextMask = mask | canTake;
               // nextMask是并行地 跳动着上课, 所以他可以用 min
               // 不想 BFS 是在 计算等待时间
               dp[nextMask] = min(dp[nextMask], dp[mask]+1);
            }
            else
            {
               for(int sub = canTake; sub > 0; sub = (sub-1) & canTake)
               {
                  if (__builtin_popcount(sub) == k)
                  {
                    int nextMask = mask | sub;
                    dp[nextMask] = min(dp[nextMask], dp[mask]+1);
                  }
               }
            }

          }

          return dp[total];

    }
};