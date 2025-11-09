class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          if (nums.empty())
            return {};

          int n = nums.size();
          int l = 0;
          int r = n - 1;

          vector<pair<int, int>> nums_pair_vec;
          vector<int> res;

          for (int i = 0; i < n; i++)
            nums_pair_vec.push_back({nums[i], i});

          sort(nums_pair_vec.begin(), nums_pair_vec.end());

          while (l < r)
          {
             long long sum = nums_pair_vec[l].first + nums_pair_vec[r].first;

             if (sum > target)
               r--;
             else if (sum < target)
               l++;
             else
             {
                res.push_back(nums_pair_vec[l].second);
                res.push_back(nums_pair_vec[r].second);
                return res;
             }
          }

          return res;
    }
};