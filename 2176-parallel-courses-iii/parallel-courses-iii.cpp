class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<vector<int>> graph(n+1);
        vector<int> inDegree(n+1, 0);

        vector<int> dp(n+1, 0);

        for (auto& edge: relations)
        {
           int prereq = edge[0];
           int course = edge[1];

           graph[prereq].push_back(course);
           inDegree[course]++;
        }

        queue<int> q;
        for(int i = 1; i <= n; i++)
        {
           if (inDegree[i] == 0)
             q.push(i);
        }

        int months = 0;
        while(!q.empty())
        {
           int q_sz = q.size();
    
           for (int i = 0; i < q_sz; i++)
           {
              int cur = q.front();
              q.pop();

              for (int nei: graph[cur])
              {
                  // dp[nei] 表示 nei 的最终等待时间
                  dp[nei] = max(dp[nei], dp[cur] + time[cur-1]);
                  inDegree[nei]--;
                  if (inDegree[nei] == 0)
                    q.push(nei);
              }
           }
        }

       int bestMonths = 0;

       // dp[i] 是 等待时间, 还要 + 这门课的耗时
       for (int i = 1; i <= n; i++)
         bestMonths = max(bestMonths, dp[i] + time[i-1]);

        return bestMonths;
        
    }
};