class Solution {
public:
int maxFrequency(vector<int>& nums, int k, int numOps)
{
    sort(nums.begin(), nums.end());         // 排序，方便二分
    int n = nums.size();

    // 收集所有候选目标值：nums[i], nums[i]-k, nums[i]+k
    set<int> cands;
    for (int x : nums)
    {
        cands.insert(x);
        cands.insert(x - k);
        cands.insert(x + k);
    }

    int ans = 0;

    for (int t : cands)
    {
        // 统计 [t-k, t+k] 范围内的元素数（都可以变成 t）
        int lo = (int)(lower_bound(nums.begin(), nums.end(), t - k) - nums.begin());
        int hi = (int)(upper_bound(nums.begin(), nums.end(), t + k) - nums.begin());
        int window = hi - lo;               // 可以变成 t 的元素总数

        // 统计已经等于 t 的元素数（不需要操作）
        int el = (int)(lower_bound(nums.begin(), nums.end(), t) - nums.begin());
        int er = (int)(upper_bound(nums.begin(), nums.end(), t) - nums.begin());
        int exact = er - el;                // 已等于 t 的数量

        // 需要操作的数量，受 numOps 限制
        int ops = min(window - exact, numOps);

        ans = max(ans, exact + ops);
    }

    return ans;
}
};