class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size();
            int n = nums2.size();

            if (!m && !n)
              return 0;
            
            if (!m)
              return findMedian(nums2);

            if (!n)
              return findMedian(nums1);
      
            int mn = m + n;
            vector<int> merged(mn);
            
            int idx1 = 0;
            int idx2 = 0;
            int idx  = 0;

            while (idx1 < m && idx2 < n)
            {
                if (nums1[idx1] < nums2[idx2])
                {
                   merged[idx] = nums1[idx1];
                   idx1++;
                }
                else
                {
                   merged[idx] = nums2[idx2];
                   idx2++;
                }

                idx++;
            }
 
           while (idx1 < m)
           {
              merged[idx] = nums1[idx1];
              idx++;
              idx1++;
           }

           while (idx2 < n)
           {
              merged[idx] = nums2[idx2];
              idx++;
              idx2++;
           }  

           return findMedian(merged);
 
    }

    double findMedian(vector<int> &merged)
    {
        int m = merged.size();
        if (m <= 0)
          return (double)0;

        int l = 0;
        int r = m - 1;
        int l_mid =  l + (r - l)/2;
        int r_mid =  l + (r - l + 1)/2;

        double res = (double)(merged[l_mid] + merged[r_mid])/2;

        return res;
    }
};