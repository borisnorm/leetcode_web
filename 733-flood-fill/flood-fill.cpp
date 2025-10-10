class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image.empty() || image[0].empty())
           return image;
        
        int m = image.size();
        int n = image[0].size();

        if (sr >=m || sr < 0 || sc >= n || sc < 0)
          return image;
        
        int origin = image[sr][sc];
        if (origin == color)
          return image;
        
        dfs(image, sr, sc, origin, color);

        return image;

    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int origin, int color)
    {
        int m = image.size();
        int n = image[0].size();

        if (sr >=m || sr < 0 || sc >= n || sc < 0)
          return;
        
        if (image[sr][sc] != origin)
          return;

        image[sr][sc] = color;

         dfs(image, sr-1, sc, origin, color);
         dfs(image, sr+1, sc, origin, color);
         dfs(image, sr, sc-1, origin, color);
         dfs(image, sr, sc+1, origin, color);

         return;
    }
};