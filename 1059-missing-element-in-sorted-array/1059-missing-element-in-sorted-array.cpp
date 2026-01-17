class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
    
        int n = nums.size();

        auto miss = [&](int i){
            return nums[i] - nums[0] - i;
        };

        if (miss(n-1) < k)
          return nums[n-1] + (k - miss(n-1));
        
        int l = 0;
        int r = n;

        // first >= k
        while(l < r)
        {
           int mid = l + (r-l)/2;
           
           if (miss(mid) < k)
              l = mid + 1;
           else
              r = mid;
        }

        return nums[l-1] + (k - miss(l-1)); 
    }
/*
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

        // the last one;
        return base + k;
    }
    */
};