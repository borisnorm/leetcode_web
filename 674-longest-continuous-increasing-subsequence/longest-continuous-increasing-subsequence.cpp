class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
    
     int n = nums.size();
     vector<int> dp(n, 1);
     // dp[i] 以 nums[i] 结尾的最长递增子序列长度 len
     // dp[j] + 1
      int maxLen = 1;
      for (int i = 1; i < n; i++)
      {
        if (nums[i] > nums[i-1])
        {
           dp[i] = dp[i-1] + 1;   
        }
        else
        {
           dp[i] = 1;
        }

        maxLen = max(maxLen, dp[i]);
      }

      return maxLen;
    }
};

/*
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
           {
             len++;
           }
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

*/