class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        int m = board.size();
        int n = board[0].size();
        
        int i = click[0];
        int j = click[1];

        if (board[i][j] == 'M')
        {
            board[i][j] = 'X';
            return board;
        }

        dfs(board, i, j);
        return board;
    
    }

    void dfs(vector<vector<char>>& board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();

        if (i < 0 || i >= m || j < 0 || j >=n)
          return;
        
        if (board[i][j] != 'E')
          return;
        //if (board[i][j] == 'B' || board[i][j] == 'X')
        //  return;
        
        //if (board[i][j] == 'E')
        {
           int cnt = 0;
           
           vector<pair<int, int>> dirs = {
               {-1, -1}, {-1, 0}, {-1, 1},
               {0,  -1},          {0, 1}, 
               {1,  -1}, {1, 0},  {1, 1} 
               };

           for (auto dir: dirs)
           {
              int nx = i + dir.first;
              int ny = j + dir.second;

              if (nx >= 0 && nx < m && ny >= 0 && ny < n)
              {
                  if (board[nx][ny] == 'M')
                    cnt++;
              }
           }

           if (cnt > 0)
           {
             board[i][j] = cnt + '0';
             return;
           }
           else
           {
             board[i][j] = 'B';
           }
           
           for (auto& dir: dirs)
             dfs(board, i + dir.first, j + dir.second);

        }
    }
};