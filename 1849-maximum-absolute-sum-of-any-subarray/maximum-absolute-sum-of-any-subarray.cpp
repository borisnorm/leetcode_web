class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // max(|abs(subarray)|)
        // 求的就是  正数最大 或是 负数最小的  子数组
        int curMax = 0;
        int curMin = 0;
        int maxSum = 0;
        int minSum = 0;

        for (int num: nums)
        {
           //要么从 num 开始, 要么从 curMax + num 向后延伸
           curMax = max(num, curMax + num);
           maxSum = max(maxSum, curMax);

           curMin = min(num, curMin + num);
           minSum = min(minSum, curMin);
        }

        return maxSum > abs(minSum) ? maxSum : abs(minSum);
    }
};