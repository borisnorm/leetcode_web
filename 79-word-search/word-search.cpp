class Solution {
public:

    bool exist(vector<vector<char>>& board, string word) {
        
        if (board.empty() || board[0].empty())
          return false;

        int m = board.size();
        int n = board[0].size();

        // Step 0 (optional pruning): frequency check
        if (!freqOk(board, word)) 
          return false;

        // dfs + backtrack
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
       board[i][j] = '#';

       bool found = dfs(board, i+1, j, word, idx+1) || 
                    dfs(board, i-1, j, word, idx+1) ||
                    dfs(board, i, j+1, word, idx+1) ||
                    dfs(board, i, j-1, word, idx+1);

       // unchoose
       board[i][j] = tmp;

       return found;
    }

      bool freqOk(const vector<vector<char>>& board, const string& word) {
        array<int, 128> cntB{};
        array<int, 128> cntW{};
        for (auto& row : board)
            for (char c : row)
                cntB[(int)c]++;

        for (char c : word) cntW[(int)c]++;

        for (int i = 0; i < 128; i++) {
            if (cntW[i] > cntB[i]) return false;
        }
        return true;
    }

};