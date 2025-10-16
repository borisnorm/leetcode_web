class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
          return res;
        if (matrix[0].empty())
          return res;

        int m = matrix.size();
        int n = matrix[0].size();
        int left_bound = 0;
        int right_bound = n - 1;
        int upper_bound = 0;
        int lower_bound = m - 1;

        while (res.size() < m * n)
        {
            //
            //    ---->
            //   ^    |
            //   |    |
            //   <----|
            //
           if (upper_bound <=  lower_bound)
           {
               for (int j = left_bound; j <= right_bound; j++)
                 res.push_back(matrix[upper_bound][j]);
               upper_bound++;
           }

           if (left_bound <= right_bound)
           {
               for (int i = upper_bound; i <= lower_bound; i++)
                 res.push_back(matrix[i][right_bound]);
               right_bound--;
           }

           if (upper_bound <= lower_bound)
           {
               for (int j = right_bound; j >= left_bound; j--)
                 res.push_back(matrix[lower_bound][j]);
               lower_bound--;
           }

           if (left_bound <= right_bound)
           {
               for (int i = lower_bound; i >= upper_bound; i--)
                 res.push_back(matrix[i][left_bound]);
               left_bound++;
           }

        }

        return res;
    }
};