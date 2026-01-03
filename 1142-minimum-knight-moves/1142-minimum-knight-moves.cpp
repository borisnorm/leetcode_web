class Solution {
public:
    int minKnightMoves(int x, int y) {
         x = abs(x);
         y = abs(y);

         vector<pair<int, int>> dirs = {
            {1, 2}, {-1, 2}, {1, -2}, {-1, -2}, 
            {2, 1}, {-2, 1}, {2, -1}, {-2, -1}
         };

         queue<pair<int, int>> q;
         q.push({0, 0});

         unordered_set<long long> visited;
         visited.insert(encode(0, 0));

         int steps = 0;
         while(!q.empty())
         {
            int q_sz = q.size();

            for (int i = 0; i < q_sz; i++)
            {
               auto [cur_x, cur_y] = q.front();
               q.pop();

               if (cur_x == x && cur_y == y)
                 return steps;
                
               for (auto d: dirs)
               {
                  int nx = cur_x + d.first;
                  int ny = cur_y + d.second;

                  if (nx < -2 || ny < -2 || nx > x + 2 || ny > y + 2)
                    continue;
                
                  long long key = encode(nx, ny);
                  if (!visited.count(key))
                  {
                     visited.insert(key);
                     q.push({nx, ny});
                  }
               }

            }

            steps++;
         }

         return -1;
    }

    long long encode(int x, int y)
    {
        return ((long long)(x + 365) << 32) | (y + 365);
    }
};