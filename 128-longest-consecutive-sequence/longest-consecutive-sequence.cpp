class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end()); // 去重 + O(1) 查找
        int ans = 0;

        for (int x : s) {
            // 只有在 x-1 不存在时，x 才可能是一个连续段的起点
            if (!s.count(x - 1)) {
                int cur = x;
                int len = 1;
                while (s.count(cur + 1)) {
                    cur++;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};