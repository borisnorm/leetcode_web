

class Solution
{
public:
    int minRemoval(vector<int>& nums, int k)
    {
        int n = nums.size();

        // 排序：使 min=nums[l], max=nums[r]，方便双指针
        sort(nums.begin(), nums.end());

        int maxLen = 0; // 最长合法窗口长度
        int l = 0;      // 左指针（枚举最小值）

        for (int r = 0; r < n; r++)
        {
            // 若当前窗口不满足 max <= k * min，收缩左边
            // 用 long long 防止 nums[l] * k 溢出 int
            //if the value of its maximum element is at most k times the minimum element.  的数学表达式
            // max <= k * min
            // max/min <= k
            // 不满足条件的就是下面
            while ((long long)nums[r] > (long long)nums[l] * k)
            {
                l++; // 左边最小值太小，排除它
            }

            // 此时窗口 [l, r] 合法
            // 窗口大小 = r - l + 1
            maxLen = max(maxLen, r - l + 1);
        }

        // 最少删除 = 总数 - 最长合法窗口 //强调最长
        return n - maxLen;
    }
};