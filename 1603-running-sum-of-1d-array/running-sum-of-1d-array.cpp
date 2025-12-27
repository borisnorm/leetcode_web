class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
         if (nums.empty())
           return {};

         int n = nums.size();

          /*
         vector<int> prefixSum(n+1, 0);

         for (int i = 1; i <= n; i++)
           prefixSum[i] = prefixSum[i-1] + nums[i-1];

         vector<int> res(prefixSum.begin() + 1, prefixSum.end());
         return res;

         */

         vector<int>  prefixSum(n, 0);
         for (int i = 0 ; i < n; i++)
           prefixSum[i] = ((i > 0) ? prefixSum[i-1] : 0) + nums[i];

         return prefixSum;
    }
};