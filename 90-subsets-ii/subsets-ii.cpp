/*
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          if (nums.empty())
            return {};

          int n = nums.size();

          vector<int> path;
          vector<vector<int>> res;
          vector<int> used(n, 0);

          sort(nums.begin(), nums.end());
          backtrack(nums, 0, path, used, res);
          return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<int>& used, vector<vector<int>>& res)
    {
       res.push_back(path);

       unordered_set<int> num_set;
       for(int i = start; i < nums.size(); i++)
       {
          //下面都是错误的
          //if (num_set.count(nums[i]))
          //  continue;
          //if (!path.empty() && nums[i] != path.back())
          //  continue;
          //if (!path.empty() && i > 0 && nums[i] == nums[i-1] && nums[i] != path.back())
          //  continue;
        
          // !used[i-1]是重点
          if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
            continue;

          path.push_back(nums[i]);
          used[i] = 1;
          //num_set.insert(nums[i]);
          backtrack(nums, i+1, path, used, res);
          path.pop_back();
          used[i] = 0;
       }
    }
};
*/

/*
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

       for(int i = start; i < nums.size(); i++)
       {
          //i > start 才是重点
          if (i > start && nums[i] == nums[i-1])
            continue;

          path.push_back(nums[i]);
        
          backtrack(nums, i+1, path, res);
          path.pop_back();
       }
    }
};
*/

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
          if (num_set.count(nums[i]))
            continue;

          path.push_back(nums[i]);
          num_set.insert(nums[i]);

          backtrack(nums, i+1, path, res);
          path.pop_back();
       }
    }
};
