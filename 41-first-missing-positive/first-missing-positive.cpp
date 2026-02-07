class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty())
          return 0;

        int n = nums.size();
 
        //put data into correct position
        // 第一步: 把每个数字放到它应该在的位置 (数字i放到索引i-1)
        // put each x into index x-1 if possible
        for (int i = 0; i < n; i++)
        {
        /* 
           也是正确的
           while (nums[i] > 0 & nums[i] < n && nums[i] != nums[nums[i]-1])
             swap(nums[i], nums[nums[i]-1]);
         */
           while (1 <= nums[i] && nums[i] <= n) 
           {
                int x = nums[i]; // [1, n] 范围的数 可以被当道 x-1的位置

                int home = x - 1;
                // 重复值来回换 会造成死循环
                //nums = [1, 1, 3]
                //i=0: nums[0]=1 已在正确位置, 停止 ✓

                //i=1: nums[1]=1 应该去索引0
                //但 nums[0] 已经是 1 了
                //nums[0] == nums[1] (都是1)
                if (nums[home] == x) 
                  break;  // duplicate / already in place

               //每次 swap 都是"把错误的数字踢走，换来另一个可能也错误的数字"

                //if：只踢一次就停，换来的数字可能还是错的
                //while：持续踢，直到当前位置的数字是正确的（或无效的） 
                swap(nums[i], nums[home]);
            }

        }

       // 第二步: 找到第一个不在正确位置的数字
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
              return i + 1;
        }

        // 第三步: 如果[1,n]都存在, 返回n+1
        return n + 1;
    }
};