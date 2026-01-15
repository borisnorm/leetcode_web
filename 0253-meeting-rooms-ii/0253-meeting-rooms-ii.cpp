class Solution {
public:
int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1)
          return n;

        // get begins and ends vector
        vector<int> begin(n);
        vector<int> end(n);
        for (int i = 0; i < n; i++)
        {
           begin[i] = intervals[i][0];
           end[i] = intervals[i][1];
        }

        // sort begin and ends
        sort(begin.begin(), begin.end());
        sort(end.begin(), end.end());

        // handle the conflict with time by sweep the line

        int i = 0;
        int j = 0;
        int room = 0;
        int res = 0;

        while (i < n && j < n)
        {
            if (begin[i] < end[j])
            {
                room++;
                i++;
            }
            else
            {
                room--;
                j++;
            }

            res = max(res, room);
        }

        return res;
}

/*
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> begin(n);
        vector<int> end(n);

        for (int i = 0; i < n; i++)
        {
          begin[i] = intervals[i][0];
          end[i] = intervals[i][1]; 
        }

        sort(begin.begin(), begin.end());
        sort(end.begin(), end.end());
        
        int i = 0;
        int j = 0;
        int room = 0;
        int res = 0;

        while (i < n && j < n)
        {
            if (begin[i] < end[j])
            {
                room++;
                i++;
                res = max(res, room);
            }
            else
            {
                room--;
                j++;
            }
        }

        return res;        
    }
    */
};