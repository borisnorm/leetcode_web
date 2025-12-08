class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();
        if (n < k)
          return 0;
      
        long long sum = 0;
        long long maxSum = 0;

        for (int i = 0; i < k; i++)
          sum += nums[i];

        maxSum = sum;

        for (int i = k; i < n; i++)
        {
           sum += nums[i] - nums[i-k];
           if (sum > maxSum)
             maxSum = sum;
        }

        return (double)maxSum/k;
    }


};