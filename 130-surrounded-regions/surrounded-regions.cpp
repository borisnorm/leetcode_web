class Solution {
public:

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m <= 1)
          return;
        int n = board[0].size();
        if (n <= 1)
          return;

        for (int i = 0; i < m; i++)
        {
            //left col
            if (board[i][0] == 'O')
              dfs(board, i, 0);

            //right col
            if (board[i][n-1] == 'O')
              dfs(board, i, n-1); 
        }

        for (int j = 0; j < n; j++)
        {
            //top
            if (board[0][j] == 'O')
              dfs(board, 0, j);

            //bottom
            if (board[m-1][j] == 'O')
              dfs(board, m-1, j);
        }

        for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
          {
              if (board[i][j] == 'O')
                board[i][j] = 'X';
              else if (board[i][j] == 'S')
                board[i][j] = 'O';
          }

        return;
    }

    void dfs(vector<vector<char>>& board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();

        if (i >= m || i < 0 || j >= n || j < 0)
          return;

        if (board[i][j] != 'O')
          return;

        board[i][j] = 'S';

        dfs(board, i-1, j);
        dfs(board, i, j-1);
        dfs(board, i+1, j);
        dfs(board, i, j+1);
    }

};