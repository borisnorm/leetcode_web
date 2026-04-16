class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int k = queries.size();

        //          val,  idx
        vector<pair<int, int>> sortedQ(k);
        for(int i= 0; i < k; i++)
          sortedQ[i] = {queries[i], i};
        sort(sortedQ.begin(), sortedQ.end());
        
        // cell_val, row, col
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false)); 

        pq.push({grid[0][0], 0, 0});

        visited[0][0] = true;

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        //cumulative reachable cells
        int count = 0;

        vector<int> res(k);

        for (auto& [qval, qidx]: sortedQ)
        {
           while (!pq.empty() && get<0>(pq.top()) < qval)
           {
              auto [val, r, c] = pq.top();
              pq.pop();
              count++;

              for (auto& d : dirs)
              {
                  int nr = r + d[0];
                  int nc = c + d[1];

                  if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc])
                    continue;
                  
                  visited[nr][nc] = true;
                  pq.push({grid[nr][nc], nr, nc});
              }
           }
           res[qidx] = count;
        }
        
        return res;
    }
};