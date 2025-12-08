class Solution {
public:
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
};