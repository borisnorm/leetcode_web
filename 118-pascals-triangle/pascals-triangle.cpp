class Solution {
public:

  vector<vector<int>> generate(int numRows) {
      vector<vector<int>> res;
      if (numRows == 0)
        return res;

      for (int i = 0; i < numRows; i++)
      {
         vector<int> row(i+1, 1);

        // 当 i = 2, 也就是 第 3行[0, 1, 2] , 第 0个元素 与 第 2个元素  不能算
        // j == 0 与 j == i 不能算,
        // 新行 有  i+1个元素, 从 [0.....i], 首尾不能算 就是 j < i 了  
         for (int j = 1; j < i; j++)
           row[j] = res[i-1][j-1] + res[i-1][j];
        
         res.push_back(row);
      }

      return res;
  }


   /*
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0)
          return {};        

        vector<vector<int>> res;
    
        res.push_back({1});
        if (numRows == 1)
          return res;

        res.push_back({1, 1});
        if (numRows == 2)
          return res;

        for (int i = 2; i < numRows; i++)
        {
            vector<int> row;
            vector<int> pre = res[i-1];
            int n = pre.size();

            row.push_back(1);
            for (int j = 1 ; j < n; j++)
            {
               row.push_back(pre[j-1] + pre[j]);   
            }
            row.push_back(1);
            

            res.push_back(row);         
        }

        return res;
    }

    */
};