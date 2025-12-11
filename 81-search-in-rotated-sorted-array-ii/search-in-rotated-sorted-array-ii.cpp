class Solution {
public:
    bool search(vector<int>& nums, int target) {
        

        int n = nums.size();
        int l = 0;
        int r = n - 1;

       // 奇数 落在 中间,  偶数 落在左侧, 所以while 循环中 l 不需要 == r
       // (0 + 1) /2 = 0
       // (1 + 2) /2 = 1
       // (2 + 3) /2 = 2
       //[l, r]
       while (l <= r)
       {
          int mid = l + (r-l)/2;

          if (nums[mid] == target)
            return true;
          
          //全相同就收缩 重新判定
          if (nums[l] == nums[mid] && nums[mid] == nums[r])
          {
             l++;
             r--;
          }
          else if (nums[mid] < nums[r])
          {
            // pivot in left side
            if (nums[mid] < target && target <= nums[r])
              l = mid + 1;
            else
              r = mid - 1;
          }
          else if (nums[mid] >= nums[l])
          {  
            // pivot in the right side
            if (nums[l] <= target && target < nums[mid])
              r = mid - 1;
            else
              l = mid + 1;
          }
          else
            r--;
       }

       return false;
    }
};