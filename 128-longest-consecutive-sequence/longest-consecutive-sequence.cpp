class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> len; // 只在区间两端保存长度
        int ans = 0;

        for (int x : nums) {
            if (len.count(x)) continue;   // 重复元素，跳过
            int L = len.count(x - 1) ? len[x - 1] : 0;
            int R = len.count(x + 1) ? len[x + 1] : 0;
            int sum = L + 1 + R;

            // 只更新新区间的左右端点
            if (L > 0) len[x - L] = sum;
            if (R > 0) len[x + R] = sum;
            len[x] = sum; // x 可能是单点段的端点（也可不存，但存更直观）

            ans = max(ans, sum);
        }
        return ans;
    }
};