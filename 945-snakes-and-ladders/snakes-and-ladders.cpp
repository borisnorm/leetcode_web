class Solution {
public:

    int getVal(vector<vector<int>>& board, int start)
    {
       int n = board.size();
       int pos = start - 1;

       int r = pos / n;
       int c = pos % n;

       if (r % 2 == 1)
         c = n - 1 - c;   //奇数行 从右向左走;
       
       r = n - 1 -r ; // 从底部 向上走
       return board[r][c];
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int goal = n * n;
        vector<bool> vis(goal+1, false);

        queue<int> q;

        q.push(1);
        vis[1] = true;

        int step = 0;

        while (!q.empty())
        {
           int q_sz = q.size();
           for (int i = 0; i < q_sz; i++)
           {
              int cur = q.front();
              q.pop();

              if (cur == goal)
                return step;

              for (int dice = 1; dice <= 6; dice++)
              {
                 int nxt = cur + dice;
                 if (nxt > goal)
                   break;
                 
                 int val =  getVal(board, nxt);
                 if (val != -1)
                   nxt = val;
                
                 if (!vis[nxt])
                 {
                    vis[nxt] = true;
                    q.push(nxt);
                 }
              }
           }
           step++;
      }
      return -1;
    }
};