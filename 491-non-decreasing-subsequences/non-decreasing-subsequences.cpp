class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
          return {};

        backtrack(nums, 0);

        return res;
    }

    void backtrack(vector<int>& nums, int start)
    {

       if (path.size() >= 2)
       {
          res.push_back(path);
       }

        int n = nums.size();
        unordered_set<int> num_set;
        for (int i = start; i < n; i++)
        {
           if (num_set.count(nums[i]))
             continue;

           if (!path.empty() && nums[i] < path.back())
           {
             //if (i >= 1 && nums[i] < nums[i-1] && path.back() == nums[i-1])
            // if (i >= 1 && nums[i] < path.back())
               continue;
           }

           path.push_back(nums[i]);
           num_set.insert(nums[i]);

           backtrack(nums, i+1);

           path.pop_back();
        }
       
    }
};