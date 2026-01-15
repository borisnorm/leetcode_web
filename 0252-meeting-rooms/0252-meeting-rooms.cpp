class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        if (intervals.empty())
          return true;

        int n = intervals.size();
        
        using T = vector<int>;
        auto cmp = [](const T& a, const T& b){ 
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        //sort(intervals.begin(), intervals.end());

        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < lastEnd)
              return false;
            
            lastEnd = intervals[i][1];
        }

        return true;
    }
};