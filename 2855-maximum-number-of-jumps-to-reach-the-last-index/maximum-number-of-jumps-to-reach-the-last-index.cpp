
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
      

       int n = nums.size();
       if (n <= 1)
         return 1;
       //
       //if (cur_idx < j && nums[cur_idx] - target <= nums[j] && nums[j] <= nums[i] + target)
       // dp[i] 到达 index i 最大的跳数, 
      
       vector<int> dp(n, -1);
       dp[0] = 0;
       for (int j = 1; j < n; j++)
       {
          for (int i = 0; i < j; i++)
          {
             //并不是 i 之前的 每个 dp[j] 都是有效的 会被计算的
             if (dp[i] == -1 )
               continue;

             if (llabs((long long)nums[j]-nums[i]) <= target)
             {
               dp[j] = max(dp[j], dp[i] + 1);
             }
          }
       }

       return dp[n-1] == -1 ? -1 : dp[n-1];
    }
};

/*
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
      

       int n = nums.size();
       if (n <= 1)
         return 1;
       //
       //if (cur_idx < j && nums[cur_idx] - target <= nums[j] && nums[j] <= nums[i] + target)
       // dp[i] 到达 index i 最大的跳数, 
      
       vector<int> dp(n, -1;
       dp[0] = 0;
       for (int i = 0; i < n; i++)
       {
          for (int j = i + 1; j < n; j++)
          {
             //并不是 i 之前的 每个 dp[j] 都是有效的 会被计算的
             if (dp[i] == -1 )
               continue;

             if (llabs((long long)nums[j]-nums[i]) <= target)
             {
               dp[j] = max(dp[j], dp[i] + 1);
             }
          }
       }

       return dp[n-1] == -1 ? -1 : dp[n-1];
    }
};

*/

/*
错误解法
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        
        //nums[i] - target <= nums[j] <= nums[i] + target

        int n = nums.size();
        vector<bool> vis(n, false);

        queue<pair<int, int>> q;
        q.push({0, 0});
        int maxStep = 0;

        while(!q.empty())
        {
          auto [cur_idx, step] = q.front();
          q.pop();

          if (cur_idx == n-1)
          { 
             maxStep = max(maxStep, step);
             continue;
          }

          // for (int j = 0; j < n; j++)
          // { 
          //   if (cur_idx < j && nums[cur_idx] - target <= nums[j] && nums[j] <= nums[i] + target)
          for (int j = cur_idx + 1; j < n; j++)
          { 
             if (((long long)nums[cur_idx] - target) <= (long long)nums[j] && (long long)nums[j] <= ((long long)nums[cur_idx] + target))
             {
                //if (vis[j])
                //  continue;
                
                //vis[j] = true;
                q.push({j, step+1}); 
             }
          }
        }

        return maxStep == 0 ? -1 : maxStep;
    }
};

*/
