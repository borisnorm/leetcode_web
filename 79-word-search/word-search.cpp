class Solution {
public:

    bool exist(vector<vector<char>>& board, string word) {
        
        if (board.empty() || board[0].empty())
          return false;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0 ; i < m; i++)
        {
          for (int j = 0; j < n; j++)
          {
            if (dfs(board, i, j, word, 0))
              return true;
          }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string word, int idx)
    {
       if (idx == word.size())
       {
         return true;
       }

       int m = board.size();
       int n = board[0].size();

       if (i < 0 || i >= m || j < 0 || j >= n)
         return false;

       if (board[i][j] != word[idx])
         return false;

       //choose
       char tmp = board[i][j];
       board[i][j] = -board[i][j];

       if (dfs(board, i+1, j, word, idx+1))
         return true;

       if (dfs(board, i-1, j, word, idx+1))
         return true;

       if (dfs(board, i, j+1, word, idx+1))
         return true;

       if (dfs(board, i, j-1, word, idx+1))
         return true;

       // unchoose
       board[i][j] = -board[i][j];

       return false;
    }
};