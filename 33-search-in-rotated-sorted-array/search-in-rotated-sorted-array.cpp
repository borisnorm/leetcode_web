class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
          return -1;

        int n = nums.size();
        int l = 0;
        int r = n - 1;

        if (n == 1)
          return nums[0] == target ? 0 : -1;

        while (l <= r)
        {
            int mid = l + (r - l)/2;
 
            if (nums[mid] == target)
              return mid;
            
            if (nums[l] <= nums[mid])
            {
               if (nums[l] <= target && target < nums[mid])
                  r = mid - 1;
               else
                  l = mid + 1;
            }
            else
            {
               if (nums[mid] < target && target <= nums[r])
                 l = mid + 1;
               else
                 r = mid - 1;
            }
        }

        return -1;
    }
};