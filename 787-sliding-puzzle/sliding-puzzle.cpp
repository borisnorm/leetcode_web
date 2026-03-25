class Solution {
public:
        // 0 1 2
        // 3 4 5
        const vector<vector<int>> neighbors = {
          {1, 3},
          {0, 2, 4},
          {1, 5},
          {0, 4},
          {1, 3, 5},
          {2, 4}
        };

    int slidingPuzzle(vector<vector<int>>& board) {
          string start = "";
          int m = board.size();
          int n = board[0].size();
          for (int i = 0; i < m; i++)
             for (int j = 0; j < n; j++)
               start += to_string(board[i][j]);

          string target = "123450";

          if (start == target)
            return 0;

          queue<string> q;
          unordered_set<string> vis;

          q.push(start);
          vis.insert(start);

          int steps = 0;

          while (!q.empty())
          {
             int q_sz = q.size();
             steps++;

             for (int i = 0; i < q_sz; i++)
             {
                // step in cur grid
                string cur = q.front();
                q.pop();

                // expand based on movable grid [0]
                int zPos = cur.find('0');
                for (int nei: neighbors[zPos])
                {
                   string next = cur;
                   // 移动格子
                   swap(next[zPos], next[nei]);
                  
                   if (next == target)
                     return steps;
                   
                   if (vis.count(next))
                     continue;
                   
                   vis.insert(next);
                   q.push(next);
                }

             }
          }

          return -1;
    }
};