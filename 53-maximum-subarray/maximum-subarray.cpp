class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = nums[0];
        int max_sum = nums[0];

         // cur_sum = max(nums[i], cur_sum + nums[i]); 是 dp
        for (int i = 1; i < nums.size(); i++) {
            cur_sum = max(nums[i], cur_sum + nums[i]);

            // 遍历 dp 求最大值
            max_sum = max(max_sum, cur_sum);
        }

        return max_sum;
    }
};


/*class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp_curSum = nums[0];

        int maxSum = dp_curSum;

        int n = nums.size();
        
        for (int i = 1; i < n; i++)
        {
            dp_curSum = max(nums[i], dp_curSum + nums[i]);

            maxSum = max(maxSum, dp_curSum);
        } 

        return maxSum;
    }
};
*/