class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;

        int zero_cnt = 0;
        int maxLen = 0;

        while (r < n)
        {
            if (nums[r] == 0)
              zero_cnt++;
            r++;

            while (zero_cnt > 1)
            {
              if(nums[l] == 0)
                zero_cnt--;
              l++;    
            }

            maxLen = max(maxLen, r-l);
        }

        return maxLen;
    }
};