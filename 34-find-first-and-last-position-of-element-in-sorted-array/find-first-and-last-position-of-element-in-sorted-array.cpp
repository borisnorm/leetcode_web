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
       int r = n -1;
       int res = -1;

       while (l <= r)
       {
         int mid = l + (r-l)/2;

         if (nums[mid] >= target)
           r = mid - 1;
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
        int r = n -1;
        int res = -1;

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