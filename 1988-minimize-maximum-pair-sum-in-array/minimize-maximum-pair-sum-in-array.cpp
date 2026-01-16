class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        sort(nums.begin(), nums.end());
        
        int maxSum = INT_MIN;
        while (l < r)
        {
            int sum = nums[l] + nums[r];

            maxSum = max(maxSum, sum);

            l++;
            r--;
        }

        return maxSum;
    }
};