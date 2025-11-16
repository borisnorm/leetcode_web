class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        if (m <= 0)
          return {};
        int n = grid[0].size();
        if (n <= 0)
          return {};

        vector<vector<int>> res(m, vector<int>(n, 0));

        k = k % (m*n);
        for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
          {
            // 2d to 1d
            int oldPos = i * n + j;
            // 1d to K
            int newPos = (oldPos + k) % (m*n);

            // new 1d to 2d
            int new_i = newPos/n;
            int new_j = newPos%n;

            res[new_i][new_j] = grid[i][j];  
          }
       
        return res;
    }
};