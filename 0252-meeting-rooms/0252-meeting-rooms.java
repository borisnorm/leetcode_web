class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        
        if (intervals == null || intervals.length <= 1)
          return true;

        int n = intervals.length;
        
        Arrays.sort(intervals, (a, b) ->Integer.compare(a[0], b[0]));

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < intervals[i-1][1])
              return false;
        }

        return true;
    }
}