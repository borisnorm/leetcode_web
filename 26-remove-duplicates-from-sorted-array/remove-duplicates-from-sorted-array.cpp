class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
          return 0;

        int n = nums.size();

        int slow = 0;

        for (int fast = 1; fast < n; fast++)
        {
           if (nums[fast] != nums[slow])
           {
              slow++;
              nums[slow] = nums[fast];
           }
        }

        return slow+1;
    }
};