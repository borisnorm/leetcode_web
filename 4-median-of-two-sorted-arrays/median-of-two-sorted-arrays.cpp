class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int prev = -1;
        int cur = -1;
       
        int total = m + n;

        int i = 0;
        int j = 0;
        for (int k = 0; k <= total/2; k++)
        {
           prev = cur;
           if (i < m && ((j < n && nums1[i] <= nums2[j]) || j >= n))
           {
              cur = nums1[i];
              i++;
           }
           else
           {
              cur = nums2[j];
              j++;
           }
        }

        if (total % 2 == 0)
          return (prev + cur)/2.0;
        else
          return cur*1.0;
    }
};
/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size();
            int n = nums2.size();

            if (m > n)
              return findMedianSortedArrays(nums2, nums1);

            
            int l = 0;
            int r = m;

            while (l <= r)
            {
               int p1 = l + (r-l)/2;
               // gurantee n1 left has more elements
               int p2 = (m+n+1)/2 - p1;

               int maxL1 = (p1 == 0) ? INT_MIN : nums1[p1-1];
               int minR1 = (p1 == m) ? INT_MAX : nums1[p1];

               int maxL2 = (p2 == 0) ? INT_MIN : nums2[p2-1];
               int minR2 = (p2 == n) ? INT_MAX : nums2[p2];

               if (maxL1 <= minR2 && maxL2 <= minR1)
               {
                  // odd number
                  if ((m+n)%2 == 1)
                  {
                    return max(maxL1, maxL2);
                  }

                  return (max(maxL1, maxL2) + min(minR1, minR2))/2.0;
               }
               else if (maxL1 > minR2)
               {
                  r = p1 - 1;
               }
               else
               {
                  l = p1 + 1;
               }
            }

            return 0.0;
    }
};

*/
/*
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

*/