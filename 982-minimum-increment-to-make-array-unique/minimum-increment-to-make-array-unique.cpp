class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ops = 0;

        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
           if (nums[i] <= nums[i-1])
           {
           
              int need = nums[i-1] + 1;
              ops += need - nums[i];
              nums[i] = need;
           }
        }

        return ops;
    }
};