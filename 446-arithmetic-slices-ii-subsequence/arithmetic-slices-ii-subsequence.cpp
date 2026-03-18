class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<long long, int>> dp(n);

        int res = 0;
        
        for (int i = 1; i < n; i++)
        {

          for (int j = 0; j < i; j++)
          {
             long long d = (long long)nums[i] - nums[j];
            
             int cnt = 0;
             if (dp[j].count(d))
              cnt = dp[j][d];
            
             //每次执行 ans += cnt 时，对应的是唯一确定的一个 (i, j) pair，d 就是那一个具体的数值。
             //因为不同的 d 代表不同的等差序列，
             //每个 j 对应独立的公差 d，找的是各自公差下的弱序列，互不干扰。
             res += cnt;

             // 本质就是：同一个 d，来自不同的 j，贡献要叠加
             // nums = [0, 2, 2, 4]
             // 
             // i=3 (val=4):
             //  j=1 (val=2): d=2 → dp[3][2] += 1+1 = 2   ← 第一次写入 d=2
             //  j=2 (val=2): d=2 → dp[3][2] += 1+1 = 2   ← 同一个 d=2，再次叠加
                                    
             // dp[3][2] = 4
             // 代表以 nums[3]=4 结尾、公差=2 的弱序列共4个：
             // {0,2,4} (来自j=1)
             // {2,4}   (来自j=1的新pair)
             // {0,2,4} (来自j=2)
             // {2,4}   (来自j=2的新pair) 
             dp[i][d] += cnt + 1;
          }
        }
        return res;
    }
};