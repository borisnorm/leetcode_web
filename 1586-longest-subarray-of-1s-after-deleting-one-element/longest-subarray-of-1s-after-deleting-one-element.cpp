class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
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
           // [l, r), 左开右闭 区间 长度 r - l,  再删除一个 字符, 就是 r - l - 1;
           ans = max(ans, r - l - 1);
        }

        return ans;
    }
};