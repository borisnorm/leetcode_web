class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 == 0 || n2 == 0 || k <= 0) return res;

        // 小顶堆：{sum, i, j}
        using T = tuple<int, int, int>;
        auto cmp = [](const T& a, const T& b) {
            return get<0>(a) > get<0>(b);   // sum 小的优先
        };
        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

        // 初始化：固定 i=0，放入前 min(k, n2) 列
        int cols = min(k, n2);
        for (int j = 0; j < cols; ++j) {
            pq.emplace(nums1[0] + nums2[j], 0, j);
        }

        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            res.push_back({nums1[i], nums2[j]});

            // 推入同一列的下一个元素 (i+1, j)
            if (i + 1 < n1) {
                int ni = i + 1;
                pq.emplace(nums1[ni] + nums2[j], ni, j);
            }
        }

        return res;
    }
};
