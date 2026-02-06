class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty())
          return;

        int n = nums.size();
        // 1. find the fisrt nums[p] < nums[p+1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i+1])
          i--;
        if (i < 0)
        {
            // 已是最大排列 -> 变最小
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2. find the fist nums[j] > nums[i]
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i])
          j--;
        
        // 3. swap p and q
        swap(nums[i], nums[j]);

        // 4. reverse after p postion suffix
        reverse(nums.begin()+i+1, nums.end());
    }
};