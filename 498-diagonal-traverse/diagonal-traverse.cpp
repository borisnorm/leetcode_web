class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> res;

        for (int d = 0; d <= m+n-2; d++)
        {
            // even number
            // i + j = d;
            if (d%2 == 0)
            {
               int i = min(d, m-1);
               int j = d - i;
               while (i >= 0 && j < n)
               {
                  res.push_back(mat[i][j]);
                  i--;
                  j++;
               }
            }
            else
            {

               int j = min(d, n-1);
               int i = d - j;

               while (i < m && j >= 0)
               {
                  res.push_back(mat[i][j]);
                  i++;
                  j--;
               }

            }
        }

        return res;
    }
};