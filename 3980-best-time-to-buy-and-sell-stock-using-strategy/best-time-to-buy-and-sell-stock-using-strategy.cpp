class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
          int n = prices.size();
          int h = k / 2;

          vector<long long> profitSum(n+1, 0);
          vector<long long> priceSum(n+1, 0);

          for (int i = 1; i <= n ; i++)
          {
             profitSum[i] = profitSum[i-1] + (long long) prices[i-1] * strategy[i-1];
             priceSum[i] = priceSum[i-1] + (long long)prices[i-1];
          }

          long long maxProfit = profitSum[n];

          for (int i = k; i <= n; i++)
          {

             long long delta = -(profitSum[i] - profitSum[i-k]) + (priceSum[i] - priceSum[i-h]);
             maxProfit = max(maxProfit, profitSum[n] + delta);
          }

          return maxProfit;
    }
};