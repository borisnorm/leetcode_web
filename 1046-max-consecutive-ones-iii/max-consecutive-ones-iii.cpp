class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if (nums.empty())
          return 0;
        
        int n = nums.size();
        if (n < k)
          return 0;

        int l = 0;
        int r = 0;
        int cnt_zero_window = 0;
        int ans = 0;
 
        while (r < n)
        {
           if (nums[r] == 0)
             cnt_zero_window++;
           r++;

           while (cnt_zero_window > k)
           {
              if (nums[l] == 0)
                cnt_zero_window--;
              l++;
           }

           ans = max(ans, r-l);
        }

        return ans;
    }
};