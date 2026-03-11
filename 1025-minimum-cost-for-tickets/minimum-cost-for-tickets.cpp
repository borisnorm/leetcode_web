class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travelDays(days.begin(), days.end());
        int lastDay = days.back();

        // past i days minimum cost on travel including the ith day

        int day1 = 0;
        int day7 = 0;
        int day30 = 0;
        vector<int> dp(lastDay+1, 0);
        for (int i = 1; i <= lastDay; i++)
        {
           if (!travelDays.count(i))
           {
             dp[i] = dp[i-1];
             continue;
           }

           day1 = dp[i-1] + costs[0];
           day7 = dp[max(0, i-7)] + costs[1];
           day30 = dp[max(0, i-30)] + costs[2];

           dp[i] = min({day1, day7, day30});
        }

        return dp[lastDay];
    }
};