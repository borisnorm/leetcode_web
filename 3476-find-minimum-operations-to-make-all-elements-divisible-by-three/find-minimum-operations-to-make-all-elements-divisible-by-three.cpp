class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // 0 3 6 9 12 

        // 0 0 1 1
        // 1 2 0 1

        // floor(1/3) = 0
        // ceil (2/3) = 0

        // floor(2/3) = 0;
        // cail (3/3) = 1
           
        // minOps += min(ceil * 3 - 2,  2 - floor * 3)

        if (nums.empty())
          return 0;
        
        int minOps = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 3 != 0)
            {
               int floor_times = nums[i]/3;
               int ceil_times  = (nums[i] + 3)/3;

               int floor_diff = abs(nums[i] - floor_times * 3);
               int ceil_diff = abs(ceil_times * 3 - nums[i]);

               minOps += min(floor_diff, ceil_diff);
            }   
        }

        return minOps;
   

    }
};