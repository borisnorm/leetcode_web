class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> track;
        vector<vector<int>> res;

        int n = nums.size();
        vector<int> used(n, 0);

        sort(nums.begin(), nums.end());
        backtrack(nums, track, used, res);

        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& track, vector<int>& used, vector<vector<int>>& res)
    {
        if (track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (used[i])
              continue;

             // if (i > 0 && nums[i] == nums[i-1] && !used[i-1])  同层去重 树层去重  效率更高
             // if (i > 0 && nums[i] == nums[i-1] && used[i-1])  不同层去重 树枝去重
            if (i > 0 &&  nums[i] == nums[i-1] && !used[i-1])
              continue;

            track.push_back(nums[i]);
            used[i] = 1;

            backtrack(nums, track, used, res);

            track.pop_back();
            used[i] = 0;
        }
    }
};