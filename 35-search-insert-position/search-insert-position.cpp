class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         if (nums.empty())
           return -1;
         
         int n = nums.size();
         int left = 0;
         int right = n;

         // [left, right)
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