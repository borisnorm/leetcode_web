class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
          return {};

          int n = (int) intervals.size();

          sort(intervals.begin(), intervals.end());

          vector<vector<int>> res;

          res.push_back(intervals[0]);

          for (int i = 1; i < n; i++)
          {
             auto& last = res.back();
             if (intervals[i][0] <= last[1])
               last[1] = max(last[1], intervals[i][1]);
             else
               res.push_back(intervals[i]);
          }

          return res;
    }
};