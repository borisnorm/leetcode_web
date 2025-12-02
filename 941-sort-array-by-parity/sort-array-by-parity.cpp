class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if (nums.empty())
          return {};

        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l < r)
        {
           if (nums[l] % 2 == 1)
           {
              if (nums[r] % 2 == 0)
              {
                  swap(nums[l], nums[r]);
                  l++;
                  r--;
              }
              else
                r--;
           }
           else
           {
              l++;
           }
        }

        return nums;
    }
};