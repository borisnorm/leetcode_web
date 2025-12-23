class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        if (nums.empty())
          return  {};
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> parent(n, -1); 

        int maxLen = 1;
        int maxIdx = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < i; j++)
           {
              //dp[i] 表示：
              //以「下标 i 处的元素 nums[i] 结尾」的最大 divisible subsequence 的长度。
              if (nums[i] % nums[j] == 0)
              {
                if (dp[j] + 1 > dp[i])
                {
                  dp[i] = dp[j] + 1;
                  parent[i] = j;
                }
              }
           }
           
           if (dp[i] > maxLen)
           {
              maxLen = dp[i];
              maxIdx = i;
           }
        }

        int cur = maxIdx;
        vector<int> res;
        while (cur != -1)
        {
          res.push_back(nums[cur]);
          cur = parent[cur];
        }

        reverse(res.begin(), res.end());

        return res;
    }
};