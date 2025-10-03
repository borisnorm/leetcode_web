class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       if (nums.empty())
         return false;
       int left = 0;
       int right = 0;
       unordered_set<int> nums_set;

       while (right < nums.size())
       {
         if (nums_set.count(nums[right]))
           return true;

         nums_set.insert(nums[right]);

         right++;
         if (abs(right - left) > k)
         {
            nums_set.erase(nums[left]);
            left++;
         }
       }

       return false;
    }
};