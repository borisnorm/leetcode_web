class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // dp[i][j] = 以nums1[i-1]和nums2[j-1]结尾的最长公共子数组长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxLen = 0; // 记录全局最大长度
        
        // 遍历所有可能的结束位置
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 如果当前元素相等
                if (nums1[i - 1] == nums2[j - 1]) {
                    // 在前一个位置的基础上+1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    // 更新最大值
                    maxLen = max(maxLen, dp[i][j]);
                }
                // 不相等时dp[i][j]保持为0（已初始化）
            }
        }
        
        return maxLen;
    }
};


/*
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        int len = 0;
        vector<vector<int>> sublen(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (i >= 1 && j >= 1 && 
                  nums1[i] == nums2[j] && 
                  nums1[i-1] == nums2[j-1])
              {
                 sublen[i][j] = sublen[i-1][j-1] + 1;
              }
              else if (nums1[i] == nums2[j])
              {
                  sublen[i][j] = 1;
              }
               
           }
        }

        int maxLen = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxLen = max(maxLen, sublen[i][j]);
            }
        }

        return maxLen;
    }
};

*/