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

          if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;

          if (board[nx][ny] == 'M')
            cnt++;
        }

        if (cnt > 0)
        {
          board[i][j] = cnt + '0';
          return;
        }
        else
        {
          board[i][j] = 'B';
           
          for (auto dir: dirs)
          {
            int nx = i + dir.first;
            int ny = j + dir.second;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
              continue;

             if (board[nx][ny] =='E')
                dfs(board, nx, ny);
          }
        }
    }
};

/*
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
      // M -> X, 只有 click 到 mine 的时候, 才会爆炸
      // E -> B
      // E -> 1-8 digit
 
      if (board.empty() || board[0].empty())
        return board;
      
      int r = click[0];
      int c = click[1];

      if (board[r][c] == 'M')
      {
         board[r][c] = 'X';
         return board;
      }

      int m = board.size();
      int n = board[0].size();
      queue<pair<int, int>> q;
      q.push({r, c});

      vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};

      while (!q.empty())
      {
         auto [x, y] = q.front();
         q.pop();

         if (board[x][y] != 'E')
           continue;

         int cnt = 0;
         for (auto dir : dirs)
         {
           int nx = x + dir.first;
           int ny = y + dir.second;
             
           if (nx < 0 || nx >= m || ny < 0 || ny >= n)
             continue;

           if (board[nx][ny] == 'M')
              cnt++;
          }

          if (cnt > 0)
          {
            //如果是数字 就不扩展
            board[x][y] = cnt + '0';
            continue;
          }

          board[x][y] = 'B';
         
          for (auto dir : dirs)
          {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
              continue;
            
            if (board[nx][ny] =='E')
              q.push({nx, ny});
          }
      }

      return board;
    }
};
*/