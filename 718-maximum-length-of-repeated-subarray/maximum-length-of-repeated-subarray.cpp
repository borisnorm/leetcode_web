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