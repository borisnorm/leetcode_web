class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        if (firstList.empty() || secondList.empty())
          return {};

        int m = firstList.size();
        int n = secondList.size();

        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {
            int a_start = firstList[i][0];
            int a_end = firstList[i][1];
            int b_start = secondList[j][0];
            int b_end = secondList[j][1];

            int L = max(a_start, b_start);
            int R = min(a_end, b_end);
            if (L <= R)
              res.push_back({L, R});

            if (a_end < b_end)
              i++;
            else
              j++;
        }

        return res;
    }
};