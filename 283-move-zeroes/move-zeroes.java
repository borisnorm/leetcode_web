class Solution {
    public void moveZeroes(int[] nums) {
        
        int n = nums.length;

        int slow = 0;
        for (int fast = 0; fast < n; fast++)
        {
           if (nums[fast] != 0)
           {
              int tmp = nums[slow];
              nums[slow] = nums[fast];
              nums[fast] = tmp;
              slow++;
           }
        }
    }
}