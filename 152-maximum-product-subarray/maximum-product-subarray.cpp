class Solution {
public:
    int maxProduct(vector<int>& nums) {
          if (nums.empty())
            return 0;
          
          int n = nums.size();
          vector<int> dp1(n, 0);
          vector<int> dp2(n, 0);

          dp1[0] = nums[0];
          dp2[0] = nums[0];

          for (int i = 1; i < nums.size(); i++)
          {
             dp1[i] = max({dp1[i-1]*nums[i], dp2[i-1]*nums[i], nums[i]});
             dp2[i] = min({dp1[i-1]*nums[i], dp2[i-1]*nums[i], nums[i]});
          }

          int max_val = INT_MIN;
          for (int i = 0; i < n; i++)
             max_val = max(dp1[i], max_val);

          return max_val;
    }
};