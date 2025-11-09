class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0)
          return {};

        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n -1;
        int target = n * n;
        int num = 1;
        vector<vector<int>> res(n, vector<int>(n));
        
        while (left <= right && top <= bottom)
        {
          if (left <= right)
          {
             for (int i = left; i <= right; i++)
               res[top][i] = num++; 
          }
          top++;

          if (top <= bottom)
          {
              for (int i = top; i <= bottom; i++)
                res[i][right] = num++;
          }
          right--;

          if (left <= right)
          {
             for (int i = right; i >= left; i--)
                res[bottom][i] = num++;
          }
          bottom--;

          if (top <= bottom)
          {
             for (int i = bottom; i >= top; i--)
               res[i][left] = num++;
          }
          left++;
        }

        return res;
    }
};