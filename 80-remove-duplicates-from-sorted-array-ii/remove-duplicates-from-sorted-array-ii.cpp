class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // remove duplicates to keep only two
        // 1 1 1 2 2  (o(1))
        // sliding window
        int n = nums.size();
        if (n <= 2)
          return n;
   
        // slow - write pointer
        // fast - read pointer
        // ************************
        //  [0, slow)  sorted area
        //  [slow fast] unknown area
        // **********************
        //  (1) the slow will be skipped for two same elements
        //  (2) the slow will be written if there
        //
        int slow = 2;
        for (int fast = 2; fast < n; fast++)
        {
          if (nums[fast] != nums[slow - 2])
          {
            nums[slow] = nums[fast];
            slow++;
          }
        }

        return slow;
    }
};