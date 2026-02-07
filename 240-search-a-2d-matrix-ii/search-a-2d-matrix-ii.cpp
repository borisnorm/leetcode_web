class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          if (matrix.empty() || matrix[0].empty())
            return false;
          
          int m = matrix.size();
          int n = matrix[0].size();
          int r = 0;
          int c = n-1;

          while (r < m && c >= 0)
          {
            int val = matrix[r][c];
            if (val < target)
            {               
               r++;
               //r = r + 1;

            }
            else if (val > target)
            {
                c--;
                //c = c - 1;
            }
            else
             return true;
          }

          return false;
    }
};


/*
  // 正确 但性能是 O(mlog(n))
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
*/