class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int totalEven = 0;
        int totalOdd = 0;

        for (int i = 0; i < n; i++)
        {
            if (i & 0x1)
              totalOdd += nums[i];
            else
              totalEven += nums[i];
        }

        int res = 0;
        int leftEven = 0;
        int leftOdd = 0;

        for (int i = 0; i < n; i++)
        {
           int rightEven = totalEven - leftEven - ((i % 2 == 0) ? nums[i] : 0);
           int rightOdd  = totalOdd - leftOdd - ((i % 2 == 1) ? nums[i] : 0);

           int newEven = leftEven + rightOdd;
           int newOdd  = leftOdd  + rightEven;

           if (newEven == newOdd)
             res++;

           if (i % 2 == 0)
             leftEven += nums[i];
           else
             leftOdd += nums[i];
        }

        return res;
    }
};