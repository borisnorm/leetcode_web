class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int zeroCnt = 0;
        int maxLen = 0;
        while (r < n)
        {
            if (nums[r] == 0)
              zeroCnt++;
            r++;

            while (zeroCnt > 1)
            {
               if (nums[l] == 0)
                 zeroCnt--;
               l++;
            }

            maxLen = max(maxLen, r-l);
        }

        return maxLen;
    }
};