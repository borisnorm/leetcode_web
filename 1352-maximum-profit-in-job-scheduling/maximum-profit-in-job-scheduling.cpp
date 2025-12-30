class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();

        vector<array<int, 3>> jobs;

        for (int i = 0; i < n; i++)
          jobs.push_back({endTime[i], startTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n+1, 0);

        for (int i = 0; i < n; i++){
            int startTime_i = jobs[i][1];
            int endTime_i = jobs[i][0];
            int profit_i = jobs[i][2];

            //  find last availele end_time <= startTime_i;
            int l = 0;
            int r = n;
            int lastAvailableIdx = i;

            while(l < r)
            {
               int mid = l + (r-l)/2;
               if (jobs[mid][0] <= startTime_i)
               {
                  lastAvailableIdx = mid;
                  l = mid + 1;
               }
               else
               {
                  r = mid;
               }
            }

            // change lastAvailable to 1-based
            lastAvailableIdx += 1;

            dp[i + 1] = max(dp[i], dp[lastAvailableIdx] + profit_i);
        
        }        

        return dp[n];
    }
};