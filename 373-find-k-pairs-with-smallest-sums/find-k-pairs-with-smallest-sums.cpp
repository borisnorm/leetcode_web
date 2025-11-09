class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 == 0 || n2 == 0 || k <= 0) 
          return res;

        using T = vector<int>;

        auto cmp = [](const T& a, const T& b){
            return a[0] > b[0];
        };

        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

        // 初始化：固定 i=0，放入前 min(k, n2) 列
        int cols = min(k, n2);
        for (int j = 0; j < cols; j++)
        {
          pq.push(T{nums1[0]+nums2[j], 0, j});
        }

        while (!pq.empty() && k > 0)
        {
            vector<int> cur = pq.top();
            pq.pop();

            int i = cur[1];
            int j = cur[2];

            res.push_back({nums1[i], nums2[j]});
            k--;

            if (i + 1 < n1) {
                pq.push(T{nums1[i+1] + nums2[j], i+1, j});
            }
        }

        return res;
    }
};
