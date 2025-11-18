class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         if (nums.empty())
           return 0;
         
         int n = nums.size();
         int l = 0;
         int r = 0;
         int cnt_zero = 0;
         int ans = 0;
         while (r < n)
         {
            if (nums[r] == 0)
              cnt_zero++;
            r++;

            if (cnt_zero > k)
            {
               if (nums[l] == 0)
                 cnt_zero--;
               l++;    
            }

            ans = max(ans, r - l);
         }

         return ans;
    }
};