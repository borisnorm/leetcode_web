class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        long total = 0;
        for (int num : nums)
          total += num;

        long leftSum = 0;
        for (int i = 0; i < n; i++)
        {
           if (2 * leftSum + nums[i] == total)
             return i;

           leftSum += nums[i];
        }

        return -1;


    }
}