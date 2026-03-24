class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
      int n = nums.size();
      int minDiff = INT_MAX;
      multiset<int> cand_i_set;

      for (int j = 0; j < n; j++)
      {
         if (j >= x)
           cand_i_set.insert(nums[j-x]);
         
         if (cand_i_set.empty())
           continue;
         
         auto it = cand_i_set.lower_bound(nums[j]);

         if (it != cand_i_set.end())
           minDiff = min(minDiff, abs(nums[j] - *it));
         
         if (it != cand_i_set.begin())
         {
            it--;
            minDiff = min(minDiff, abs(nums[j] - *it));
         }

         if (minDiff == 0)
           return 0;
      }

      return minDiff;
    }
};

/* 
// 超时 TLE
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        int n = nums.size();
        int minDiff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int j = i + x;
            while (j < n)
            {
               int diff = abs(nums[i] - nums[j]);
               minDiff = min(minDiff, diff);
               
               j++;
            }
        }

        return minDiff;
    }
};
*/