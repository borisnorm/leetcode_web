class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;

        int l = 0;
        int r = 0;
        int cnt_zero_window = 0;
        int ans = 0;

        while (r < n)
        {
           if (nums[r] == 0)
             cnt_zero_window++;
           r++;
   
           while (cnt_zero_window > 1)
           {
              if (nums[l] == 0)
                cnt_zero_window--;
              l++;
           }

           ans = Math.max(ans, r-l-1);
        }

        return ans;
    }
}