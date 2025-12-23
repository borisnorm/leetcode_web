class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 按宽度升序，宽度相同则高度降序
        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        int n = envelopes.size();
        vector<int> dp(n, 1);
        int result = 1;
        
    // 2. 对高度做 LIS
        vector<int> lis;
        for (auto& e : envelopes) {
            int h = e[1];
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end())
                lis.push_back(h);
            else
                *it = h;
        }
        return lis.size();
    }
};

/*
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        if (envelopes.empty())
          return 0;

        int n = envelopes.size();

        vector<int> dp(n, 1);

        using T = vector<int>;
        auto cmp = [](const T& a, const T& b){
              if (a[0] == b[0])
                 return a[1] > b[1];
            
              return a[0] < b[0];
        };

        sort(envelopes.begin(), envelopes.end(), cmp);

        int maxNum = 0;
      
        for (int i = 0; i < n; i++)
        {
           vector<int> envlop_i = envelopes[i];
           for (int j = 0; j < i; j++)
           {
              vector<int> envlop_j = envelopes[j];

             // if (envelopes[j][0] < envelopes[i][0] &&
             //     envelopes[j][1] < envelopes[i][1]) 
              if (envlop_j[0] < envlop_i[0] && 
                  envlop_j[1] < envlop_i[1])
              {
                 dp[i] = max(dp[i], dp[j] + 1);
              }
              
           }
           
           maxNum = max(maxNum, dp[i]);
        }

        //for (int i = 0; i < n; i++)
        //    maxNum = max(maxNum, dp[i]);

        return maxNum;
    }
};

*/