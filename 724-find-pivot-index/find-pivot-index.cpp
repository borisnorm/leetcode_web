class Solution {
public:

    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        long long total = 0;
        for (int num : nums)
          total += num;
        
        long long leftSum = 0;
        // leftSum == rightSum
        //         == total - nums[i] - leftSum
        // 2*leftSum + nums[i] == total
        for (int i = 0; i < n; i++)
        {
           if (2 * leftSum + nums[i] == total)
             return i;
          
           leftSum += nums[i];
        }

        return -1;

    }

    /*
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r)
        {
            int leftSum = 0;
            for (int i = 0; i < l; i++)
              leftSum += nums[i];
            
            int rightSum = 0;
            for (int i = n - 1; i >= (l + 1); i--)
              rightSum += nums[i];

            if (leftSum == rightSum)
              return l;
        
           l++;
        }

        return -1;
    }

    */
};