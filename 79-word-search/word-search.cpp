class Solution {
public:

    bool exist(vector<vector<char>>& board, string word) {
        
        if (board.empty() || board[0].empty())
          return false;

        int m = board.size();
        int n = board[0].size();

        // Step 0 (optional pruning): frequency check
        if (!freqchk(board, word)) 
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

    //如果 word 里某个字符出现的次数，比整个 board 里该字符的总次数还多，那一定不可能找到路径
    bool freqchk(vector<vector<char>>& board, string& word)
    {
       // 这是错误的
       //int[128] board_freq;
       //int[128] word_freq;

       int board_freq[128];
       int word_freq[128];

        for (auto s: board)
        {
          for (char c: s)
            board_freq[c]++;
        }

       for (char c: word)
         word_freq[c]++;
        
        for (int i = 0; i < 128; i++)
        {
          if (board_freq[i] < word_freq[i])
            return false;
        }
        return true;
    }

};