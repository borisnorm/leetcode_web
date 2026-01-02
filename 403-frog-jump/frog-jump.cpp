class Solution {
public:
    bool canCross(vector<int>& stones) {
         int n = stones.size();

         unordered_map<int, int> pos2idx;
         for (int i = 0; i < n; i++)
           pos2idx[stones[i]] = i;

         vector<unordered_set<int>> dp(n);
         dp[0].insert(0);

         for (int i = 0; i < n; i++)
         {
            for (int k : dp[i])
            {
               for (int step = k - 1; step <= k + 1; step++)
               {
                  if (step <= 0)
                    continue;
                
                  int nextPos = stones[i] + step;
                  if (pos2idx.count(nextPos))
                  {
                     int j = pos2idx[nextPos];
                     dp[j].insert(step);
                  }
               }
            }
         }

         return dp[n-1].empty() ? false : true;


    }
};