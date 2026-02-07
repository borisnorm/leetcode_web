
class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) { 
         if (matrix.empty() || matrix[0].empty())
           return;
        
         int m = matrix.size();
         int n = matrix[0].size();

         int row0 = 0;
         int col0 = 0;
         for(int i = 0; i < m; i++)
         {
           if (matrix[i][0] == 0)
           {
              row0 = 1;
              break;
           }
         }

        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
               col0 = 1;
               break;
            }
        }


        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                   matrix[0][j] = 0;
                   matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] ==0)
                    matrix[i][j] = 0;
            }
        }

        if (row0)
        {
            for (int i = 0; i < m; i++)
              matrix[i][0] = 0;
        }

        if (col0)
        {
            for (int j = 0; j < n; j++)
              matrix[0][j] = 0;
        }
    }
};
/* not in place
class Solution {
public:
    vector<vector<int>> visited;

    void setZeroes(vector<vector<int>>& matrix) { 
          if (matrix.empty() || matrix[0].empty())
            return;
           
          int m = matrix.size();
          int n = matrix[0].size();

          vector<int> row(m, 0);
          vector<int> col(n, 0);

          for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
              if (matrix[i][j] == 0)
              {
                  row[i] = 1;
                  col[j] = 1;
              }

          for (int i = 0; i < m; i++)
            if (row[i])
              for (int j = 0; j < n; j++)
                matrix[i][j] = 0;
        
           for (int j = 0; j < n; j++)
             if (col[j])
               for (int i = 0; i < m; i++)
                 matrix[i][j] = 0;
    }
};

*/