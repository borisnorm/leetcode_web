class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {         
         int n = nums.size();
         if (n <= 0)
           return {-1, -1};

        int start = findFirst(nums, target);
        int end = findLast(nums, target);

        return {start, end};
    }

    
    //普通二分没找到目标时，终止状态永远是：

    //hi 指向最后一个 < target 的位置
    //lo 指向第一个 > target 的位置

    // 对于 闭区间 的 while(l<= r),    
    // r 可能向左移动, 致使 l > r, l 也可能向右移动, 致使 l > r,
    // 对于闭区间
    // 找左边界        lo 是答案
    // 找右边界        hi 是答案
    // 所以 使用 res 更安全
    //
    // 如果这个数存在, 是在找 lower_bound 与 upper_bound, 
    // 如果不存在, 就返回 {-1, -1} 
    // 如果只存在 唯一的一个数, 是不是 start 与 end 是同一个 pos 值
    //
    //  searchRange 本质就是 [lower_bound, upper_bound - 1] 
    //  所以即使使用闭区间写法 end position 也要 l - 1 才行
    //
    // >= 
    int findFirst(vector<int>& nums, int target)
    {
       int n = nums.size();
       int l = 0;
       int r = n -1;
       int res = -1;

       while (l <= r)
       {
         int mid = l + (r-l)/2;

         if (nums[mid] >= target)
           r = mid - 1;
         else
           l = mid + 1;
        
        //这里用 res 记录每次命中的 mid，因为闭区间写法循环结束时 lo > hi，lo 不一定是答案。
        // if (nums[mid] == target)
        //   res = mid;
       }

       if (l < n && nums[l] == target)
         res = l;

       return res;
    }

    int findLast(vector<int>& nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n -1;
        int res = -1;

        // find first > target
        while (l <= r)
        {
           int mid = l + (r - l)/2;
           if (nums[mid] > target)
             r = mid - 1;
           else
             l = mid + 1;
          
           if (nums[mid] == target)
             res = mid;
        }

        return res;
    }
};


/*
开区间
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {         
         int n = nums.size();
         if (n <= 0)
           return {-1, -1};

        int start = findFirst(nums, target);
        int end = findLast(nums, target);

        return {start, end};
    }

    int findFirst(vector<int>& nums, int target)
    {
       int n = nums.size();
       int l = 0;
       int r = n;
       int res = -1;

       while (l < r)
       {
         int mid = l + (r-l)/2;

         if (nums[mid] >= target)
           r = mid;
         else
           l = mid + 1;
        
         if (nums[mid] == target)
           res = mid;
       }

       return res;
    }

    int findLast(vector<int>& nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n;
        int res = -1;

        while (l < r)
        {
           int mid = l + (r - l)/2;
           if (nums[mid] > target)
             r = mid;
           else
             l = mid + 1;
          
           if (nums[mid] == target)
             res = mid;
        }

        return res;
    }
};
*/