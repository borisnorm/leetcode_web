class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
          return 0;

        unordered_set<int> nums_set(nums.begin(), nums.end());

        int ans = 0;
        int cur_len = 0;
        int cur_num = 0;
        for (int num : nums_set)   // for (int num: nums_set)
        {
           if (!nums_set.count(num-1))
           {
              // this num is the start point
              cur_len = 1;
              cur_num = num;

              while (nums_set.count(cur_num+1))
              {
                cur_len++;
                cur_num = cur_num + 1;
              }
           }

           ans = max (ans, cur_len);
        }

        return ans;
    }
};
