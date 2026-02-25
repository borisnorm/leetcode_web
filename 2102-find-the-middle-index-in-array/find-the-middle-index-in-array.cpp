class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        long long total = 0;
        for (int num: nums)
          total += num;

        int n = nums.size();
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 0; i < n; i++)
        {
           rightSum = total - leftSum - nums[i];
           if (leftSum == rightSum)
             return i;
            
           leftSum += nums[i];
        }

        return -1;
    }
};