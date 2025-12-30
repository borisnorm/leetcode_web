class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        
        int n = present.size();

        vector<int> dp(budget+1, 0);

        for (int i = 0; i < n; i++)
        {
           int cost = present[i];
           int gain = future[i] - present[i];

           for (int j = budget; j >= cost; j--)
             dp[j] = max(dp[j], dp[j-cost] + gain);
        }

        return dp[budget];
    }
};