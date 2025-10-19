class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min_price = INT_MAX;
       int max_profit = 0;

       for (int p: prices)
       {
          if (p < min_price)
            min_price = p;
          else
            max_profit = max(max_profit, (p-min_price));
       }

       return max_profit;
    };
   
};