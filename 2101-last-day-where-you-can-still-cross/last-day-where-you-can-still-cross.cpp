class Solution {
public:
       vector<pair<int, int>> dirs = {{0, 1},  {0, -1},  {1, 0},  {-1, 0}};
    bool canCross(int row, int col, vector<vector<int>>& cells, int mid)
    {
       // 0 - land
       vector<vector<int>> grid(row, vector<int>(col, 0));
       for (int i = 0; i < mid; i++)
       {
          int x = cells[i][0] - 1;
          int y = cells[i][1] - 1;
          grid[x][y] = 1;
       }

       queue<pair<int, int>> q;

       for (int j = 0; j < col; j++)
       {
          if (grid[0][j] == 0)
          {
             q.push({0, j});
          }
       }


       while (!q.empty())
       {
          auto [x, y] = q.front();
          q.pop();

          if (x == row -1)
            return true;

          for (auto dir : dirs)
          {
             int nx = x + dir.first;
             int ny = y + dir.second;

             if (nx < 0 || nx >= row || ny < 0 || ny >= col)
               continue;
              
             if (grid[nx][ny] != 0)
                continue;

              grid[nx][ny] = 1;
              q.push({nx, ny});
          }
          
       }

       return false;
    }


    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 1;
        int hi = cells.size();  // cells 这里表示了 天数
        int lastDay = 0;

        while (lo <= hi)
        {
           int mid = lo + (hi-lo)/2;
            
           if (canCross(row, col, cells, mid))
           {
              lastDay = mid;
              lo =  mid + 1;
           }
           else
           {
              hi =  mid - 1;
           }
        }

        return lastDay;

    }
};