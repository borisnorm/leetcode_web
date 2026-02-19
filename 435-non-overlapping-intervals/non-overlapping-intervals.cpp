class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1)
          return 0;
        
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){return a[1] < b[1];});

        int removed = 0;
        
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= lastEnd)
            {
               lastEnd = intervals[i][1];
            }
            else
            {
               removed++;
            }
        }

        return removed;
        
    }
};
/*
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

        // 按照 end 排序后的第一个interval 是结束最早的, 可以保留的
        int cnt = 1;

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

*/