class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
          
          int n = nums.size();
          if (n == 0 || n < k)
            return false;
          
          int pre_idx = -1;
          for (int i = 0; i < n; i++)
          {
             if (nums[i] == 1)
             {
                int cur_idx = i;
                if (pre_idx != -1 && cur_idx - pre_idx - 1 < k)
                  return false;
                
                pre_idx = cur_idx;
             }
          }

         // if (pre_idx == -1 || (pre_idx != -1 && pre_idx != (n-1) && (n - pre_idx - 1 < k)))
         //if ( (pre_idx != -1 && pre_idx != (n-1) && (n - pre_idx - 1 < k)))
         //   return false;
        
          return true;
    }
};