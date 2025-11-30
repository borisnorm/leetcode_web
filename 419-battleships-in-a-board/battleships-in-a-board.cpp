class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0)
          return 0;
        int n = board[0].size();
        if (n == 0)
          return 0;

        int cnt = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && board[i][j] == 'X')
                {
                   cnt++;
                   dfs(board, i, j, visited);
                }
            }
        }

        return cnt;
    }

    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>>& visited)
    {
       int m = board.size();
       int n = board[0].size();

       if (i < 0 || i >= m || j < 0 || j >= n)
         return;
    
       if (visited[i][j] || board[i][j] != 'X')
         return;

        visited[i][j] = 1;
        dfs(board, i+1, j, visited);
        dfs(board, i-1, j, visited);
        dfs(board, i, j+1, visited);
        dfs(board, i, j-1, visited);
    }
};