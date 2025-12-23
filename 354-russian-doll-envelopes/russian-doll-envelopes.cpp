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

        vector<int> lis;
       // lis[k] 不是在回答“能装多少”
       // lis[k] 是在回答：
       // “长度为 k+1 的链，存不存在？”

       //lis 做的事情是：
       //对每一个可能的长度 k+1
       //维护一个 “存在性证明”
       //而这个证明形式是： 
       //存在一条长度为 k+1 的递增链，
       //且它的结尾最小可以做到 lis[k]
       //👉 一旦 lis[k] 存在，就说明：
       //长度为 k+1 的嵌套方案是存在的

        for (int i = 0; i < n; i++)
        {
           int h = envelopes[i][1];
            
           auto it = lower_bound(lis.begin(), lis.end(), h);

           if (it == lis.end())
             lis.push_back(h);
           else
             *it = h;
        }

        return lis.size();
        /*
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
       */
    }
};

