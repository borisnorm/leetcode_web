class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        int n = nums.size();
        vector<vector<int>> res;

        long long cur  = 0;
        long long prev = (long long)lower-1; 
        for (int i = 0; i <= n; i++)
        {
            cur = (i < n) ? nums[i] : (long long) upper + 1;

            if (cur - prev >= 2)
            {
              res.push_back({(int)prev+1, (int)cur-1});
            }

            prev = cur;

        }

        return res;
    }
};