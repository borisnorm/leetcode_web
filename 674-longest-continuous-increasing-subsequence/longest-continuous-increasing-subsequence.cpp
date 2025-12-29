class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int n = nums.size();
        if (n <= 1)
          return n;

        int len = 1;
        int maxLen = INT_MIN;
        for (int i = 1; i < n; i++)
        {
           if (nums[i] > nums[i-1])
             len++;
           else
           {     
             maxLen = max(maxLen, len);
             len = 1;
           }
        }

        maxLen = max(maxLen, len);

        return maxLen;
    }
};