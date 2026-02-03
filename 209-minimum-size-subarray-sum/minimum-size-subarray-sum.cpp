class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
         int n = nums.size();

         int r = 0;
         int l = 0;

         int minLen = INT_MAX;
         int window_sum = 0;
         while (r < n)
         {
             window_sum += nums[r];
             r++;

             while (window_sum >= target)
             {
                minLen = min(minLen, (r-l));
                window_sum -= nums[l];
                l++;
             }
         }

         return (minLen == INT_MAX) ? 0 : minLen;
    }
};