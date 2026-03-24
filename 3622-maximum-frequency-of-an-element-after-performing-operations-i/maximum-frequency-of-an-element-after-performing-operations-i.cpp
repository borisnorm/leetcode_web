class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        set<int> cands;
        for (int num: nums)
        {
           cands.insert(num);
           cands.insert(num - k);
           cands.insert(num + k);
        }

        int res = 0;
        for (int target: cands)
        {
           int lo = (int)(lower_bound(nums.begin(), nums.end(), target-k) - nums.begin());
           int hi = (int)(upper_bound(nums.begin(), nums.end(), target+k) - nums.begin());
           //[low, hi)
           int window = hi - lo; 

           int exact_lo = (int)(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
           int exact_hi = (int)(upper_bound(nums.begin(), nums.end(), target) - nums.begin());

           int exact = exact_hi - exact_lo;

           //需要操作的数量，受 numOps 限制, 所以是 min
           int ops = min(numOperations, window-exact);

           res = max(res, exact + ops);
        }

        return res;        
    }
};