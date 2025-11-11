class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         if (nums.empty())
           return INT_MAX;
         int n = nums.size();
         if (n < 3)
           return INT_MAX;
         
         sort(nums.begin(), nums.end());  //关键

         long long best = nums[0] + nums[1] + nums[2];
         for (int i = 0; i < n - 2; i++)
         {
           int l = i + 1;
           int r = n - 1;

           while (l < r)
           {
             long long sum = nums[i] + nums[l] + nums[r];
              
              if (llabs(sum - target) < llabs(best - target))
                best = sum;

              if (sum > target)
                r--;
              else  if (sum < target)
                l++;
              else
                return target; 
           }
         }

         return best;
    }
};