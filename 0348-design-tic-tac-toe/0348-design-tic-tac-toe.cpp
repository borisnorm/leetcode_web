class TicTacToe {
public:
    vector<int> rows, cols;
    int diag, antiDiag;
    int n;
    TicTacToe(int n): rows(n, 0), cols(n, 0), diag(0), antiDiag(0), n(n) {
        
    }
    
    int move(int row, int col, int player) {
         int val =  (player == 1) ? 1 : -1;
         
         rows[row] += val;
         cols[col] += val;
         
         if (row == col)
           diag += val;
         if (row + col == n - 1)
           antiDiag += val;
        
         if (abs(rows[row]) == n || abs(cols[col]) == n ||  abs(diag) == n || abs(antiDiag) == n)
           return player;

          return 0;
        
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */