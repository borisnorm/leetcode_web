class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

      int n = nums.size();
      sort(nums.begin(), nums.end());
      int l = 0;
      int r = n - 1;
      int opscnt = 0;

      while (l < r)
      {
        int sum = nums[l] + nums[r];
        if (sum < k)
          l++;
        else if (sum > k)
          r--;
        else
        {
           opscnt++;
           l++;
           r--;
        }
      }

      return opscnt;
    }
};