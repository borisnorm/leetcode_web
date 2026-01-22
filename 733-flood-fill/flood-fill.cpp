class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         if (image.empty() || image[0].empty())
           return {};
        
         int m = image.size();
         int n = image[0].size();

         if (sr < 0 || sr >= m || sc < 0 || sc >= n)
           return {};
        
         int origin = image[sr][sc];
         if (origin == color)
           return image;
        
         queue<pair<int, int>> q;
         q.push({sr, sc});
         image[sr][sc] = color;

         vector<pair<int, int>> dirs = {
                 {-1, 0},
            {0, -1},  {0, 1},
                 {1, 0}
         };

         while(!q.empty())
         {
            int q_sz = q.size();
            for (int i = 0; i < q_sz; i++)
            {
                auto [x, y] = q.front();
                q.pop();

                for (auto d : dirs)
                {
                   int nx = x + d.first;
                   int ny = y + d.second;

                   if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                     continue;

                   if (image[nx][ny] != origin)
                     continue;
                   
                   image[nx][ny] = color;
                   q.push({nx, ny});
                }
            }
         }

         return image;
         
    }

/*
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
             if(image.empty() || image[0].empty())
               return {};
             int m = image.size();
             int n = image[0].size();
             
             if (sr < 0 || sr >= m || sc < 0 || sc >= n)
               return {};
             
             int origin = image[sr][sc];
             if (origin == color)
               return image;

             dfs(image, sr, sc, origin, color);

             return image;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int origin, int color)
    {
        int m = image.size();
        int n = image[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n)
          return;
        
        if (image[r][c] != origin)
          return;
        
        image[r][c] = color;

        dfs(image, r+1, c, origin, color);
        dfs(image, r-1, c, origin, color);
        dfs(image, r, c+1, origin, color);
        dfs(image, r, c-1, origin, color);
    }

    */
};