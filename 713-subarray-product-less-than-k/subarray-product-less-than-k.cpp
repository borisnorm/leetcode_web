class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        

         int n = nums.size();
         int l = 0;
         int r = 0;
         int product = 1;

         int res = 0;
 
         while (r < n)
         {
            product *= nums[r];
            r++;

            while (l < r && product >= k)
            {
               product /= nums[l];
               l++;
            }
 
            res+=(r-l);

         }

         return res;
    }
};