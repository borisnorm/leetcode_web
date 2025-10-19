class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;   // 到目前为止见过的最低买入价
        int max_profit = 0;        // 最大收益（不能为负）
        for (int p : prices) {
            if (p < min_price) {
                min_price = p;     // 更新最低买点
            } else {
                // 以今天价格作为卖点，尝试更新收益
                max_profit = max(max_profit, p - min_price);
            }
        }
        return max_profit;
    }
};