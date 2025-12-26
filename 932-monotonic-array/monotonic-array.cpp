class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        if (nums.empty())
          return false;
        
        int n = nums.size();
        vector<int> status(n, 0);
        // 1 5 7 4 1 2
        int preStatus = 0;
        int curStatus = 0;
        for (int i = 1; i < n; i++)
        {
           int diff = nums[i] - nums[i-1];
           if (diff > 0)
              curStatus = 1;
           else if (diff < 0)
              curStatus = -1;
            else 
              curStatus = preStatus;
           
           if (preStatus != 0 && curStatus != preStatus)
             return false;

            preStatus = curStatus;             
        }

        return true;
    }
};