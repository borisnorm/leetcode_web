class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
       int n = board.size();

       int xCnt = 0;
       int oCnt = 0;
       for (int i = 0; i < n; i++)
       {
         for (int j = 0; j < n; j++)
         {
            if (board[i][j] == 'X')
              xCnt++;
            else if (board[i][j] == 'O')
              oCnt++;
         }
       }
       // 1. check x, o count
       if (!(xCnt == oCnt || xCnt == oCnt + 1))
         return false;
       
       auto winCheck = [&](char role)->bool{

          for (int i = 0; i < n; i++)
          {
             if (board[i][0]== board[i][1] && board[i][1] == board[i][2] && board[i][0] == role)
               return true;
          }

          for (int j = 0; j < n; j++)
          {
             if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == role)
               return true;
          }

          for (int i = 0; i < n; i++)
          {
             if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == role)
               return true;
             if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == role)
               return true; 
          }

          return false;
       };
       bool xWin = winCheck('X');
       bool oWin = winCheck('O');

       // 2. x win, x more than o
       if (xWin && xCnt != oCnt + 1)
         return false;

       // 3. o win, x == o
       if (oWin && xCnt != oCnt)
         return false;

       // 4. x 与 o 不能同时赢
       if (xWin && oWin)
         return false;
      
       return true;
    }
};