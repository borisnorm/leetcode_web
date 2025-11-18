class Solution {
public:
    int maxProduct(vector<int>& nums) {
          if (nums.empty())
            return 0;
          
          int n = nums.size();
          vector<long long> dpMax(n, 1);
          vector<long long> dpMin(n, 1);
          dpMax[0] = nums[0];
          dpMin[0] = nums[0];

          long long ans = nums[0];

          for (int i = 1; i < n; i++)
          {
              long long x = nums[i];
              long long dpMaxVal = dpMax[i-1] * x;
              long long dpMinVal = dpMin[i-1] * x;
            
              dpMax[i] = max({x, dpMaxVal, dpMinVal});
              dpMin[i] = min({x, dpMaxVal, dpMinVal});
              
              ans = max(ans, dpMax[i]);
          }

          return (int)ans;
    }
};


