class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size();

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
           int j = i;
           sum += mat[i][j];
           //int j = n - i - 1;
                   //3 - 1 - 1 = 1
                   //3 - 2 - 1 = 0
           if (i != (n - i - 1))
           {
              j = n - i - 1;
              sum += mat[i][j];
           }
        }

        return sum;
    }
};