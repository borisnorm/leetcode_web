class Solution {
public:
   int minimumOperations(vector<int>& nums) {
        if (nums.empty())
         return 0;

       // 一次操作可以对某个元素 `+1` 或 `-1`。
       //对任意数 `x`，只看 `r = x % 3`：
       //r == 0`：已经能被 3 整除，0 次
       //r == 1`：`x-1` 就能整除，1 次（比 `x+2` 更优）
       //r == 2`：`x+1` 就能整除，1 次（比 `x-2` 更优）

       //所以每个元素只要 **不是 3 的倍数，就一定需要 1 次操作**。
       // 答案就是统计 `num % 3 != 0` 的个数。 
        int minOps = 0;
        for (int i = 0; i < nums.size(); i++)
          if (nums[i] % 3 != 0)
            minOps++;
        return minOps;
   }
    /*
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
    */
};