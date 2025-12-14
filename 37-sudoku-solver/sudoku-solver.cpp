class Solution {
public:
    bool rowUsed[9][10] = {};
    bool colUsed[9][10] = {};
    bool boxUsed[9][10] = {};
    
    int boxId(int r, int c)
    {
      return (r/3) * 3 + (c/3);
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++)
        {
           for (int c = 0; c < 9; c++)
           {
              if (board[r][c] == '.')
                continue;
            
              int d = board[r][c] - '0';
              int b = boxId(r, c);

              rowUsed[r][d] = colUsed[c][d] = boxUsed[b][d] = true;
           }
        }
        backtrack(board);
    }

    bool backtrack(vector<vector<char>>& board)
    {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] != '.')
                   continue;
                
                int b = boxId(r, c);
                for (int d = 1; d <= 9; d++)
                {
                    if (rowUsed[r][d] || colUsed[c][d] || boxUsed[b][d])
                      continue;
                    
                    //try
                    board[r][c] = d + '0';
                    rowUsed[r][d] = colUsed[c][d] = boxUsed[b][d] = true;

                    if (backtrack(board))
                      return true;
                    
                    //rollback
                    rowUsed[r][d] = colUsed[c][d] = boxUsed[b][d] = false;
                    board[r][c] = '.';

                }

                return false;
            }
        }

        return true;
    }
};