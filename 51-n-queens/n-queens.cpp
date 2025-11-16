class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        vector<string> board(n, string(n, '.'));

        vector<bool> colUsed(n, false);

        vector<bool>diagUsed(2*n - 1, false);

        vector<bool> antiDiagUsed(2*n-1, false);

        backtrack(0, n, board, colUsed, diagUsed, antiDiagUsed, res);

        return res;
    }

    void backtrack(int row, int n, vector<string>& board, vector<bool>& colUsed, vector<bool>& diagUsed, vector<bool>& antiDiagUsed, vector<vector<string>>& res)
    {
        if (row == n)
        {
           res.push_back(board);
           return;
        }

        for (int col = 0; col < n; col++)
        {
            int diagIndex = row - col + n - 1;
            int antiDiagIndex = row + col;

            if (colUsed[col] || diagUsed[diagIndex] || antiDiagUsed[antiDiagIndex])
              continue;

            board[row][col] = 'Q';
            colUsed[col] = true;
            diagUsed[diagIndex] = true;
            antiDiagUsed[antiDiagIndex] = true;

            backtrack(row+1, n, board, colUsed, diagUsed, antiDiagUsed, res);

            board[row][col] = '.';
            colUsed[col] = false;
            diagUsed[diagIndex] = false;
            antiDiagUsed[antiDiagIndex] = false;
        }
    }
};