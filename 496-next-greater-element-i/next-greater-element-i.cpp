class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
           map<int, int> nums2_val2idx;

           int m = nums1.size();
           int n = nums2.size();

      
           for (int j = 0; j < n; j++)
             nums2_val2idx[nums2[j]] = j;
        
           vector<int> res(m, -1);

           for (int i = 0; i < m; i++)
           {
              if (nums2_val2idx.count(nums1[i]))
              {
                   int target = nums1[i];
                   for (int j = nums2_val2idx[nums1[i]] + 1; j < n; j++)   
                   {
                      if (nums2[j] > target)
                      {
                         res[i] = nums2[j];
                         break;

                      }
                   }   
              }
           }

           return res;
    }
};