class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

         int m = nums1.size();
         int n = nums2.size();
         int p = nums3.size();
         int q = nums4.size();

         unordered_map<long long, int> sum2freq;

         int res = 0;

         for (int a: nums1)
         {
            for (int b: nums2)
            {
               int sum = a+b;
               sum2freq[sum]++;
            }
         }

         for (int c: nums3)
         {
            for (int d: nums4)
            {
               int sum = -(c+d);
               if (sum2freq.count(sum))
               {
                  res += sum2freq[sum];
               }
            }
         }
        
        return res;
    }
};