class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        
        int n = nums.size();
        
        //even
        for (int i = 0; i < n; i+=2)
        {
            int minIdx = i;
            int minVal = nums[i];

            for (int j = i + 2; j < n; j+=2)
            {
               if (nums[j] < minVal)
               {
                  minIdx = j;
                  minVal = nums[j];
               }
            }

            if (i != minIdx)
              swap(nums[i], nums[minIdx]);
        }

        //odd
        for (int i = 1; i < n; i+=2)
        {
            int maxIdx = i;
            int maxVal = nums[i];

            for (int j = i + 2; j < n; j+=2)
            {
                if (nums[j] > maxVal)
                {
                   maxIdx = j;
                   maxVal = nums[j];
                }
            }

            if (i != maxIdx)
              swap(nums[i], nums[maxIdx]);
        }

        return nums;
    }
};