class Solution {
    public int minMeetingRooms(int[][] intervals) {
            int n = intervals.length;

            int[] begin = new int[n];
            int[] end = new int[n];

            for (int i = 0; i < n; i++)
            {
                 begin[i] = intervals[i][0];
                 end[i] = intervals[i][1];
            }

            Arrays.sort(begin);
            Arrays.sort(end);

            int i = 0;
            int j = 0;
            int room = 0;
            int maxConflict = 0;

            while (i < n && j < n)
            {
                if (begin[i] < end[j])
                {
                    i++;
                    room++;
                }
                else{
                    j++;
                    room--;
                }

                maxConflict = Math.max(maxConflict, room);
            }

            return maxConflict;
    }
}