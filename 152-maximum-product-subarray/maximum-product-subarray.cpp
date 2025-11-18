class Solution {
public:
    int maxProduct(vector<int>& nums) {
          if (nums.empty())
            return 0;
          
          int n = nums.size();

          long long maxVal = nums[0];
          long long minVal = nums[0];
          long long ans = nums[0];

          for (int i = 1; i < n; i++)
          {
              long long x = nums[i];
              if (x < 0)
                swap(maxVal, minVal);
            
              maxVal = max(x, maxVal * x);
              minVal = min(x, minVal * x);

              ans = max(ans, maxVal);
          }

          return (int)ans;
    }
};


       //   vector<long long> dpMax(n, 1);
       //   vector<long long> dpMin(n, 1);