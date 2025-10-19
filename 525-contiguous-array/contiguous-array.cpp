class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       if (nums.empty())
         return 0;

       int n = nums.size();
       unordered_map<int, int> pos;

       int sum = 0;
       int ans = 0;

       for (int i = 0; i < n; i++)
       {
          sum += nums[i] ? 1 : -1;
          if (sum == 0)
          {
             ans = i + 1;
          }
          else if (pos.count(sum))
          {
             ans = max(ans, i - pos[sum]);
          }
          else
          {
             pos[sum] = i;
          }
       }

       return ans;
      

    }
};