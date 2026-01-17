class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        
        int n = nums.size();
        int base = nums[0];
        if (k == 0)
          return base;
        
        int missing = 0;
        for (int i = 1; i < n; i++)
        {
           int gap = nums[i] - base - 1;
           missing  = base + k;

           if (gap >= k)
             return missing;
          
           k = k - gap;
           base = nums[i];
        }

        return base + k;
    }
};