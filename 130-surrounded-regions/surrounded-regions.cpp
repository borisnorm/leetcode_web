
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // 1. mark the edges
        // left most and right most
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
              bfs(board, i, 0);
            
            if (board[i][n-1] == 'O')
              bfs(board, i, n-1);
        }

        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O')
              bfs(board, 0, j);
            
            if (board[m-1][j] == 'O')
              bfs(board, m-1, j);
        }

        //top and bottom

        //2. reverse edge and capture the 'O' and replace to 'X' 
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                  board[i][j] = 'X';
                else if (board[i][j] == 'S')
                  board[i][j] = 'O';
            }
        }
    }

    void bfs(vector<vector<char>>& board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();


        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = 'S';
      
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop(); 

            for (auto dir: dirs)
            {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                  continue;
                
                if (board[nx][ny] != 'O')
                  continue;
                
                board[nx][ny] = 'S';

                q.push({nx, ny});
            }
        }
    }
};


/*
class Solution {
public:

    // DFS 的解法不是 最优的
    // Time: O(M x N)  — 每个格子最多访问一次
    // Space: O(m × n) — DFS 递归栈最坏情况（全是O）
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m <= 1)
          return;
        int n = board[0].size();
        if (n <= 1)
          return;

        // 不能被 capture, 因为 surround 要求 边 全部是 'X' 
        //   x x x x 
        //   x o o x  
        //   x o o x 
        //   x o x x 

        // 下边的不能 被 capture,  右上角的可以被 capture, 
        // 只要 O 被 X 四面包围就可以，不要求 X 在边界上。
        // 题目的真正条件只有一个：
        // 这块 O 连通块，有没有任何一个 O 碰到棋盘边界
        // 没碰到边界 → 被包围 → 翻转
        // 碰到边界 → 不被包围 → 保留

        // x x x x x x
        // x x x o o x
        // x x x o o x
        // x x x x x x
        // x o o x x x
        // x o x x x x

        // 1. 从4边开始 标记 边上的 'O' 以及相连 'o' 为 'S'
        //   要 check 边上的 cell 是不是 'O' 
        // the most left col and the most right col
        for (int i = 0; i < m; i++)
        {
            //left col
            if (board[i][0] == 'O')
              dfs(board, i, 0);

            //right col
            if (board[i][n-1] == 'O')
              dfs(board, i, n-1); 
        }

        // the most top and the most bottom row
        for (int j = 0; j < n; j++)
        {
            //top
            if (board[0][j] == 'O')
              dfs(board, 0, j);

            //bottom
            if (board[m-1][j] == 'O')
              dfs(board, m-1, j);
        }

        // 2.翻转 + capture, 重新标记 O
        for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
          {
              if (board[i][j] == 'O')
                board[i][j] = 'X';
              else if (board[i][j] == 'S')
                board[i][j] = 'O';
          }

        return;
    }

    void dfs(vector<vector<char>>& board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();

        if (i < 0 || i >= m || j < 0|| j >= n)
          return;

        if (board[i][j] != 'O')
          return;

        board[i][j] = 'S';

        dfs(board, i-1, j);
        dfs(board, i, j-1);
        dfs(board, i+1, j);
        dfs(board, i, j+1);
    }

};
*/