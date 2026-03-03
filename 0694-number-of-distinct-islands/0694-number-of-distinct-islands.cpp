class Solution {
public:


    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
          return 0;
     
        using T = set<pair<int, int>>;
        set<T> shapes;
        
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    T shape;
                    dfs(grid, i, j, i, j, shape);
                    shapes.insert(shape);
                }
            }
        }

        return shapes.size();
    }

    void dfs(vector<vector<int>>& grid, int orig_i, int orig_j, int i, int j, set<pair<int, int>>& shape)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n)
          return;
        
        if (grid[i][j] != 1)
          return;
        
        grid[i][j] = 0;

        shape.insert({i-orig_i, j-orig_j});

        dfs(grid, orig_i, orig_j, i+1, j, shape);
        dfs(grid, orig_i, orig_j, i-1, j, shape);
        dfs(grid, orig_i, orig_j, i, j+1, shape);
        dfs(grid, orig_i, orig_j, i, j-1, shape);
    }
};