class Solution {
public:
    vector<int> track;
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int> nums, int start)
    {
        res.push_back(track);
        
        int n = nums.size();
        for (int i = start; i < n; i++)
        {
          track.push_back(nums[i]);
          backtrack(nums, i+1);
          track.pop_back();
        }
    }
};