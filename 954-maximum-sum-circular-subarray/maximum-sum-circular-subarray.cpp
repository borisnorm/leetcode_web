class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        long long total = 0;

        long long curMax = 0;
        long long maxSum = LLONG_MIN;
        long long curMin = 0;
        long long minSum = LLONG_MAX;

        for (int x : nums)
        {
            total += x;

            curMax = max<long long>(x, curMax + x);
            maxSum = max(maxSum, curMax);

            curMin = min<long long>(x, curMin + x);
            minSum = min(minSum, curMin);
        }

        if (maxSum < 0)
          return (int)maxSum;
        
        long long wrap = total-minSum;

        return (int)max(maxSum, wrap);
    }
};