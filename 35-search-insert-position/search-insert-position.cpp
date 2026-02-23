class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
            if (nums.empty())
              return 0;
            
            int n = nums.size();
            int l = 0;
            int r = n - 1;
            while (l <= r)
            {
                int mid = l + (r-l)/2;

                if (nums[mid] == target)
                  return mid;
                
                if (nums[mid] >= target)
                  r = mid-1;
                else
                  l = mid+1;
            }

            return l;
    }
};
/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         if (nums.empty())
           return -1;
         
         int n = nums.size();
         int left = 0;
         int right = n;

         // [left, right)
         // 停止时 left == right  第一个 >= target 的位置 
         while (left < right)
         {
            int mid = left + (right - left)/2;
            if (nums[mid] < target)
              left = mid + 1;
            else if (nums[mid] > target)
              right = mid;
            else 
              return mid;
         }

         return left;
    }
};

*/