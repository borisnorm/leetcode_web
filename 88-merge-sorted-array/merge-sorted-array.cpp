class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         if (nums1.empty() || nums2.empty())
           return;
        int k = nums1.size() - 1;
        

        int i = m-1;
        int j = n-1;

        while (i >=0 && j >=0 && k >=0)
        {
            if (nums1[i] >= nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

       /* 
        // 已经在 nums1上有序了
        while (i >=0 && k >= 0)
        {
           nums1[k] = nums1[i];
           i--;
           k--;
        }
        */

        while (j >=0 && k >= 0)
        {
           nums1[k] = nums2[j];
           j--;
           k--;
        }
    }
};