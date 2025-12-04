class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        
        while (fast < n)
        {
          if (nums[fast] != 0)
          {
             swap(nums[slow], nums[fast]);
             slow++;
          }
        
          fast++;
        }
    }
};