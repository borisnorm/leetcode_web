class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty())
          return {};
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> pacVis(m, vector<int>(n, 0));
        vector<vector<int>> atlVis(m, vector<int>(n, 0));
        
        //queue<pair<int, int>> pac_q;
        //queue<pair<int, int>> atl_q;

        vector<pair<int, int>> pac_q;
        vector<pair<int, int>> atl_q;
      
        for (int i = 0; i < m; i++)
        {
            pac_q.push_back({i, 0});
            atl_q.push_back({i, n-1});
        }

        for (int j = 0; j < n; j++)
        {
           pac_q.push_back({0, j});
           atl_q.push_back({m-1, j});
        }
        
        bfs(pac_q, pacVis, heights);
        bfs(atl_q, atlVis, heights);

        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              if (pacVis[i][j] && atlVis[i][j])
                res.push_back({i,j});
           }
        }

        return res;
    }

    void bfs(vector<pair<int, int>>& begin_vec, vector<vector<int>>& vis, vector<vector<int>>& heights)
    {
        int m = vis.size();
        int n = vis[0].size();

        queue<pair<int, int>> q;
        for (auto& [x, y]: begin_vec)
        {
            q.push({x, y});
            vis[x][y] = 1;
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1},  {1, 0},  {-1, 0}};
        while(!q.empty())
        {
           auto [x, y] = q.front();
           q.pop();

           for (auto& dir : dirs)
           {
              int nx = x + dir.first;
              int ny = y + dir.second;

              if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
              
              if (vis[nx][ny] == 1)
                continue;

              if (heights[x][y] <= heights[nx][ny])
              {
                  vis[nx][ny] = 1;
                  q.push({nx, ny});
              }
           }
        }
    }
};
/*
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      if (heights.empty() || heights[0].empty())
        return {};

      int m = heights.size();
      int n = heights[0].size();

      vector<vector<int>> pacific(m, vector<int>(n, 0));
      vector<vector<int>> atlantic(m, vector<int>(n, 0));

      //pacific ocean
      // the most left col  
      for (int i = 0; i < m; i++)
        dfs(i, 0, pacific, heights);
     
      // the top row
      for (int j = 0; j < n; j++)
        dfs(0, j, pacific, heights);

      //atlantic ocean
      // the bottom row
      for (int i = 0; i < m; i++)
        dfs(i, n-1, atlantic, heights);
    
      for (int j = 0; j < n; j++)
        dfs(m-1, j, atlantic, heights);

      vector<vector<int>> res;

     for (int i = 0; i < m; i++)
     {
       for (int j = 0; j < n; j++)
       {
          if (pacific[i][j] && atlantic[i][j])
            res.push_back({i, j});
       }
     }

     return res;
  }

    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& heights)
    {

        static int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int m = vis.size();
        int n = vis[0].size();

        vis[r][c] = 1;

        for (auto& dir : dirs)
        {
          int nr = r + dir[0];
          int nc = c + dir[1];

          if (nr < 0 || nr >= m || nc < 0 || nc >= n)
            continue;

          //                    中心          >=   边沿
          if (!vis[nr][nc] && heights[nr][nc] >= heights[r][c])
            dfs(nr, nc, vis, heights);
        }
    }
};

*/