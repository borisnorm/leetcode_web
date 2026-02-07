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
           while (nums[i] > 0 & nums[i] < n && nums[i] != nums[nums[i]-1])
             swap(nums[i], nums[nums[i]-1]);
         */
           while (nums[i] >= 1 && nums[i] <= n) 
           {
                int x = nums[i];
                int home = x - 1;
                if (nums[home] == x) 
                  break;  // duplicate / already in place

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