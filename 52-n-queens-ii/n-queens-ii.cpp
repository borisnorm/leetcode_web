class Solution {
public:

    int count = 0;

    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;


    int totalNQueens(int n) {

        col.assign(n, false);
        diag1.assign(2*n-1, false);
        diag2.assign(2*n-1, false);

        dfs(0, n);

        return count;
    }

    void dfs(int row, int n)
    {
       if  (row == n)
       {
          count++;
          return;
       }

       for (int c = 0; c < n; c++)
       {

            if (col[c])
              continue;
            
            if (diag1[row - c + n - 1])
              continue;
            
            if (diag2[row + c ])
              continue;
            

            col[c] = true;
            diag1[row - c + n - 1] = true;
            diag2[row + c] = true;

            dfs(row + 1, n);


            col[c] = false;
            diag1[row - c + n - 1] = false;
            diag2[row + c] = false;
       }
    }
};