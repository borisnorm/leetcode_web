class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        if (n <= 2)
          return n;
        
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
           unordered_map<long long, int> cnt; //slopeKey -> count
           int dup = 0;
           int best = 0;

           long long x1 = points[i][0];
           long long y1 = points[i][1];

           for (int j = i + 1; j < n; j++)
           {
              long long x2 = points[j][0];
              long long y2 = points[j][1];

              long long dx = x2-x1;
              long long dy = y2-y1;

              if (dx == 0 && dy == 0)
              {
                 dup++;
                 continue;
              }

              if (dx == 0)
                dy = 1;
              else if (dy == 0)
                dx = 1;
              else
              {
                 long long g = gcd(llabs(dy), llabs(dx));

                 dy /= g;
                 dx /= g;
                
                 if (dx < 0)
                 {
                    dx = -dx;
                    dy = -dy;
                 }
              }

              long long key = (dy + 2000000000LL) << 32 ^ (dx & 0xffffffffll);
              cnt[key]++;

              best = max(best, cnt[key]);
           }
           
           ans = max(ans, best + dup + 1);
        }

        return ans;
    }
};