class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          if (nums.empty())
            return {};
          
          vector<int> path;
          vector<vector<int>> res;
          sort(nums.begin(), nums.end());
          backtrack(nums, 0, path, res);
          return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res)
    {
       res.push_back(path);

       unordered_set<int> num_set;
       for(int i = start; i < nums.size(); i++)
       {
          //if (num_set.count(nums[i]))
          //  continue;
          //if (!path.empty() && nums[i] != path.back())
          //  continue;
          //if (!path.empty() && i > 0 && nums[i] == nums[i-1] && nums[i] != path.back())
          //  continue;

          if (i > start && nums[i] == nums[i-1])
            continue;

          path.push_back(nums[i]);
          //num_set.insert(nums[i]);
          backtrack(nums, i+1, path, res);
          path.pop_back();
       }
    }
};

