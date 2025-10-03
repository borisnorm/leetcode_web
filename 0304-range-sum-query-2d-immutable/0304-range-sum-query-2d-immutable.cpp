class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n_row = matrix.size();
        int n_col = matrix[0].size();
    
        preSum.resize(n_row);
        for (auto& iter: preSum)
           iter.resize(n_col+1);
        
        for (int i = 0; i < n_row; i++)
          for (int j = 0; j< n_col; j++)
              preSum[i][j+1] = preSum[i][j] + matrix[i][j];

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        
        for (int i= row1; i<= row2; i++)
          sum+= preSum[i][col2+1]-preSum[i][col1];
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */