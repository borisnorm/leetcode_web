class Solution {
public:

 vector<int> sortEvenOdd(vector<int>& nums){
         
         int n = nums.size();

        // int odd_n = (n%2) ? (n/2 + 1) : n/2;
       //  int even_n = n/2;

       //✅ (n + 1) / 2 才是始终正确的公式
      //❌ n / 2 + 1 在 n 为偶数时会多算 1

         vector<int> odd;
         vector<int> even;

         for (int i = 0; i < n; i++)
         {
            if (i & 0x1)
              odd.push_back(nums[i]);
            else
              even.push_back(nums[i]);
         }

        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());
    
        int odd_idx = 0;
        int even_idx = 0;
        for (int i = 0; i < n; i++)
        {
           if (i & 0x1)
             nums[i] = odd[odd_idx++];
           else
             nums[i] = even[even_idx++];
        }

        return nums;
 }

/*
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
    */
};