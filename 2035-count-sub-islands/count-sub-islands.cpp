class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();

        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1)
                {
                    if (dfs(grid2, i, j, grid1))
                      cnt++;
                }
            }
        }

        return cnt;
    }

    bool dfs(vector<vector<int>>& grid2, int i, int j, vector<vector<int>>& grid1)
    {
        int m = grid2.size();
        int n = grid2[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n)
          return true;
        
        if (grid2[i][j] != 1)
          return true;
        
        grid2[i][j] = 0;

        bool matched = false;
        if (grid1[i][j] == true)
          matched = true;
        
        matched = dfs(grid2, i+1, j, grid1) & matched;
        matched = dfs(grid2, i-1, j, grid1) & matched;
        matched = dfs(grid2, i, j+1, grid1) & matched;
        matched = dfs(grid2, i, j-1, grid1) & matched;

        return matched;
    }
};  