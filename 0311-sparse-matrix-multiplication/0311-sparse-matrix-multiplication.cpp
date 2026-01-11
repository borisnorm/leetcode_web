class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
          int m = mat1.size();
          int k = mat2.size();
          int n = mat2[0].size();
 
          vector<vector<pair<int, int>>> mat2_non_zero(k);

          for (int i = 0; i < k; i++)
          {
            for (int j = 0; j < n; j++)
            {
                if (mat2[i][j] != 0)
                  mat2_non_zero[i].push_back({j, mat2[i][j]});
            }
          }

          vector<vector<int>> res(m, vector<int>(n));

          for (int i = 0; i < m; i++)
          {
             for (int p = 0; p < k; p++)
             {
                  if (mat1[i][p]!= 0)
                  {                     
                      for (auto& [j, val]: mat2_non_zero[p])
                        res[i][j] += mat1[i][p]* val; 
                  }
             }
          }


          return res;

    }
};