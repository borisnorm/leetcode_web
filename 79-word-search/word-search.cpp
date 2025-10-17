class Solution {
public:
    bool found = false;
    bool exist(vector<vector<char>>& board, string word) {
        
        if (board.empty())
          return false;
        if (board[0].empty())
          return false;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0 ; i < m; i++)
        {
          for (int j = 0; j < n; j++)
          {
            dfs(board, i, j, word, 0);
            if (found)
              return true;
          }
        }

        return found;
    }

    void dfs(vector<vector<char>>& board, int i, int j, string word, int idx)
    {
       if (idx == word.size())
       {
         found = true;
         return;
       }

       int m = board.size();
       int n = board[0].size();

       if (i < 0 || i >= m || j < 0 || j >= n)
         return;

       // terminate if already found
       if (found)
         return;

       if (board[i][j] != word[idx])
         return;

       //choose
       board[i][j] = -board[i][j];

       dfs(board, i+1, j, word, idx+1);  
       dfs(board, i-1, j, word, idx+1);    
       dfs(board, i, j+1, word, idx+1);  
       dfs(board, i, j-1, word, idx+1);

       // unchoose
       board[i][j] = -board[i][j];
    }
};