class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if (intervals.empty())
          return 0;

        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        };

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        int x_end = intervals[0][1];
        int cnt = 1;

        for (auto& interval : intervals)
        {
           int start = interval[0];
           if (start >= x_end)
           {
              cnt++;
              x_end = interval[1];
           }
        }

        return n - cnt;

    }
};