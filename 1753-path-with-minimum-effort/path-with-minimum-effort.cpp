class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0});

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!pq.empty())
        {
          auto [cur_effort, i, j] = pq.top();
          pq.pop();

          if (cur_effort > effort[i][j])
             continue;

          if (i == m - 1 && j == n -1)
             return cur_effort;
          
          for (auto dir :  dirs)
          {
             int nI = i + dir.first;
             int nJ = j + dir.second;

             if (nI < 0 || nI >= m || nJ < 0 || nJ >= n)
               continue;
              
             int new_effort = max(cur_effort, abs(heights[nI][nJ] - heights[i][j]));
             if (new_effort < effort[nI][nJ])
             {
                effort[nI][nJ] = new_effort;
                pq.push({new_effort, nI, nJ});
             }
          }
        }
        return effort[m-1][n-1];
    }
};