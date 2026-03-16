class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        
        using T = vector<int>;
        auto cmp = [](const T& a, const T& b){
           return a[1] < b[1];
        };
        // 按结束时间 升序 排列
        sort(events.begin(), events.end(), cmp);

        int n = events.size();

        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

        for (int i = 1; i <= n; i++)
        {
          int start = events[i-1][0];
          int val = events[i-1][2];

          int l = 0;
          int r = i-1;
          int prev = 0;

          while (l <= r)
          {
             int mid = l + (r-l)/2;
             if (events[mid][1] < start)
             {
                // prev+1 is 1-based
                prev = mid + 1;
                l = mid + 1;
             }
             else
                r = mid - 1;
          }

          for (int j = 1; j <= k; j++)
          {
             //不参加第 i 个事件
             int skip = dp[i-1][j];


            // 参加 第个时间: 从 prev 中 取 j-1个事件 + 当前这个事件
             int take = dp[prev][j-1] + val;
             
             dp[i][j] = max(skip, take);
          }
        }

        return dp[n][k];
    }
};