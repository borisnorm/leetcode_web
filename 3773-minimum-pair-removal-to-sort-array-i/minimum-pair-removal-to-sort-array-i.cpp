class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        
        auto sorted = [&]() -> bool {
            int n = nums.size();
            for (int i = 0; i + 1 < n; i++)
            {
               if (nums[i] > nums[i+1])
                 return false;
            }

            return true;
        };

        int ops = 0;
        while(!sorted())
        {
          // nums[i] + nums[i+1] 合并
          long long minVal = LLONG_MAX;
          int minIdx = 0;
          for (int i = 0; i + 1 < nums.size(); i++)
          {
              //               必须加上 long long 防止越界
              long long sum = (long long)nums[i] + nums[i+1];
              if (sum < minVal)
              {
                 minVal = sum;
                 minIdx = i;
              }
          }

          nums[minIdx] = (int)minVal;
          nums.erase(nums.begin() + minIdx + 1);
          ops++;
        }
        
        return ops;
    }
};