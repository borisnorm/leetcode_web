class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
       
         int n = nums.size();
         vector<int> dp(n+1, 0);

         //空前缀的方案数 partition 是 1
         dp[0]=1;

         deque<int> minQ;
         deque<int> maxQ;
         long long const MOD = 1e9+7;

         int l = 0;
         long long sumDp = 0;
         //dp[i] = dp[l] + dp[l+1]....dp[r];
         for (int r = 0; r < n; r++)
         {
            sumDp = (sumDp + dp[r]) % MOD;
            //front...back : front->min  //单调增
            while(!minQ.empty() && nums[r] <= nums[minQ.back()])
              minQ.pop_back();
            minQ.push_back(r);

            //front.. back ; front->max // 单调减
            while(!maxQ.empty() && nums[r] >= nums[maxQ.back()])
              maxQ.pop_back();
            maxQ.push_back(r);   
            
            while (!minQ.empty() && !maxQ.empty() && 
                   (nums[maxQ.front()] - nums[minQ.front()]) > k)
            {    
                //经过前面的 pop_back 才做, minQ 与 maxQ 已经是 单调递增 或是单调递减的 queue
                // 如果 l 是中间的 某个值 nums[l], 它早就 弹出了. 
                if (maxQ.front() == l)
                  maxQ.pop_front();

                if (minQ.front() == l)
                  minQ.pop_front();

                sumDp = (sumDp - dp[l] + MOD) % MOD;
                l++;
            }

            dp[r+1] = (int)sumDp;
         }

         return dp[n];
    }
};