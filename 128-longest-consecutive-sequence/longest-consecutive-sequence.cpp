class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 转化成哈希集合，方便快速查找是否存在某个元素
        unordered_set<int> set(nums.begin(), nums.end());

        int res = 0;

        for (int num : set) {
            if (set.find(num - 1) != set.end()) {
                // num 不是连续子序列的第一个，跳过
                continue;
            }
            // num 是连续子序列的第一个，开始向上计算连续子序列的长度
            int curNum = num;
            int curLen = 1;

            while (set.find(curNum + 1) != set.end()) {
                curNum += 1;
                curLen += 1;
            }
            // 更新最长连续序列的长度
            res = max(res, curLen);
        }

        return res;
    }
};