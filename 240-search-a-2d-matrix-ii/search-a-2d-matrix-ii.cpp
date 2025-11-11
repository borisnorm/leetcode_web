class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n <= 0)
          return false;
        int m = matrix[0].size();
        if (m <= 0)
          return false;

        for (int i = 0; i < n; i++)
        {
           if (matrix[i][0] > target)
             break;  

           if (matrix[i][m-1] < target)
             continue;

           int l = 0;
           int r = m;
           while (l < r)
           {
              int mid = l + (r - l)/2;
              if (matrix[i][mid] < target)
                 l = mid + 1;
              else if (matrix[i][mid] > target)
                 r = mid;
              else
                 return true;
           }
        }

        return false;
    }
};