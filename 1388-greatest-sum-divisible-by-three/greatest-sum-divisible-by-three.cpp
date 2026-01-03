class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        

        vector<int> dp(3, 0);

        for (int num: nums)
        {
           vector<int> tmp = dp;
           for (int i = 0; i < 3; i++)
           {
               int remainder = (tmp[i] + num) % 3;
               dp[remainder] = max(dp[remainder], tmp[i]+num);
           }
        }

        return dp[0];
    }
};