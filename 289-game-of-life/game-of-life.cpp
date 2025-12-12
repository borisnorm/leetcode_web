class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> dirs = {
               {-1, -1},  {-1, 0},  {-1, 1},
               {0,  -1},            {0,  1},
               {1,  -1},  {1,  0},  {1,  1} 
        };

        for (int i = 0; i < m; i++)
        {
           for (int j = 0; j < n; j++)
           {
              int live = 0;
               
               for (auto& d: dirs)
               {
                  int ni = i + d.first;
                  int nj = j + d.second;
                  if (ni < 0 || ni >= m || nj < 0 || nj >=n)
                    continue;

                   if (board[ni][nj] == 1 || board[ni][nj] == 2)
                     live++; 
               }

               if (board[i][j] == 1)
               {
                  if (live < 2 || live > 3)
                    board[i][j] = 2;
               }
               else
               {
                  if (live == 3)
                    board[i][j] = 3;
               }
           }
        }

        /* update board based on status */
        for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
            board[i][j] = board[i][j] % 2;

        
    }
};