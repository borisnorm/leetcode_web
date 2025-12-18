class Solution {
public:

    vector<int> getRow(int rowIndex) {

        //  每一行里面有  rowIndex + 1 个元素
        vector<int> row(rowIndex+1, 0);
        row[0] = 1;

        for (int i = 1; i <= rowIndex; i++)
        {
           for (int j = i;  j >= 1; j--)
             //把 上一行的 元素 拷贝过来, 再跟 上一行 的元素 相加
             row[j] += row[j-1];
        }

        return row;

    }
    
    /*
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> pascal;

        vector<int> row0 = {1};
        vector<int> row1 = {1, 1};

        pascal.push_back(row0);
        pascal.push_back(row1);

        int nrow = rowIndex + 1;
        
        for (int i = 2; i < nrow; i++)
        {
            int ncol = i + 1;
            vector<int> col(ncol);
            for (int j = 0; j < ncol; j++)
              col[j] = ((j-1 < 0) ? 0 : pascal[i-1][j-1]) + ((j >= pascal[i-1].size()) ? 0: pascal[i-1][j]);
            
            pascal.push_back(col);
        }

        return pascal[rowIndex];
    }
    */
};