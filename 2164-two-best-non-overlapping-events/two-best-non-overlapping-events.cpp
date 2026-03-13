class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end());

        int n = events.size();

        vector<int> surfixMax(n+1, 0);

        for (int i = n-1; i >= 0; i--)
        {
           surfixMax[i] = max(surfixMax[i+1], events[i][2]);
        }

        int maxSum = 0;
        for (int i = 0; i < n; i++)
        {
          int endT = events[i][1];
          int val  = events[i][2];

          int l = i + 1;
          int r = n;

          while (l < r)
          {
             int mid = l + (r-l)/2;
             if (events[mid][0] > endT)
               r = mid;
             else
               l = mid + 1;
          }

          //我们要的就是 后面的这个 l, 
          maxSum = max(maxSum, val + surfixMax[l]);
        }

        return maxSum;
    }
};