class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        


        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;
        vector<int> col(n, INT_MAX);

        for (int i = 0; i < m; i++)
        {
            int minRowVal = INT_MAX;
            int maxColVal = INT_MIN;
            int minVal_Col = 0;
            for (int j = 0; j < n; j++)
            {
              minVal_Col = (matrix[i][j] <= minRowVal) ? j : minVal_Col; 
              minRowVal = min(minRowVal, matrix[i][j]);
            }

            if (col[minVal_Col] == INT_MAX)
            {
              for (int k = 0; k < m; k++)
                 maxColVal = max(maxColVal, matrix[k][minVal_Col]);

              col[minVal_Col] = maxColVal;
            }

            if (col[minVal_Col] == minRowVal)
                  res.push_back(minRowVal);
        }

        return res;
    }
};