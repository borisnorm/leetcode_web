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

        int lastEnd = intervals[0][1];
        int cnt = 1;

        //for (auto& interval : intervals)
        for (int i = 1; i < n; i++)
        {
           //不重叠的 new_start >= lastEnd
           if (intervals[i][0] >= lastEnd)
           {
              cnt++;
              lastEnd = intervals[i][1];
           }
        }

        return n - cnt;

    }
};