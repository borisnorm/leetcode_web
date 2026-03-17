class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       int n = nums.size();

       for (int i = 0; i + 1 < n; i++)
       {
          bool shouldSwap = (i & 0x1) ? nums[i] < nums[i+1] : nums[i] > nums[i+1];
          if (shouldSwap)
            swap(nums[i], nums[i+1]);
       } 
    }
};