class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {         
         int n = nums.size();
         vector<int> res;
         if (n <= 0)
           return {-1, -1};

        int start = findLeftRange(nums, target);
        int end = findRightRange(nums, target);
        
        res.push_back(start);
        res.push_back(end);

        return res;
    }

    int findLeftRange(vector<int>& nums, int target)
    {
       int n = nums.size();
       int l = 0;
       int r = n -1;
       int ans = -1;
       while (l <= r)
       {
         int mid = l + (r-l)/2;
         if (nums[mid] >= target)
           r = mid - 1;
         else
           l = mid + 1;
        
         if (nums[mid] == target)
           ans = mid;
       }

       return ans;
    }

    int findRightRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n -1;
        int ans = -1;

        while (l <= r)
        {
           int mid = l + (r - l)/2;
           if (nums[mid] <= target)
             l = mid + 1;
           else
             r = mid - 1;
          
           if (nums[mid] == target)
             ans = mid;
        }

        return ans;
    }
};