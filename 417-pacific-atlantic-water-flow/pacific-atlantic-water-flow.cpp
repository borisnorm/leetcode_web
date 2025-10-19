

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         if (heights.empty())
           return {};

         if (heights[0].empty())
           return {};

         int m = heights.size();
         int n = heights[0].size();

         vector<vector<int>> pac(m, vector<int>(n, 0));
         vector<vector<int>> alt(m, vector<int>(n, 0));

    auto dfs = [&](auto&& self, int r, int c, vector<vector<int>>& vis) -> void {
      vis[r][c] = 1;
      static int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      for (auto& d : dirs)
      {
        int nr = r + d[0];
        int nc = c + d[1];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n)
          continue;
        if (!vis[nr][nc] && heights[nr][nc] >= heights[r][c])
          self(self, nr, nc, vis);
      }
    };
 
    //pac 
    for (int r = 0; r < m; r++)
      dfs(dfs, r, 0, pac);
    
    for (int c = 0; c < n; c++)
      dfs(dfs, 0, c, pac);

    //alt
    for (int r = 0; r < m; r++)
      dfs(dfs, r, n-1, alt);
    
    for (int c = 0; c < n; c++)
      dfs(dfs, m-1, c, alt);

    vector<vector<int>> ans;

    for (int r = 0; r < m; r++)
      for (int c = 0; c < n; c++)
         if (pac[r][c] && alt[r][c])
           ans.push_back({r, c});

    return ans;





    }
};