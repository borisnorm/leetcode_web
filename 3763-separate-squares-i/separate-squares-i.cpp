class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double lo = 1e5;
        double hi = 0;
        for (auto& sq: squares)
        {
           double y = sq[1];
           double l = sq[2];
           lo = min(lo, y);
           hi = max(hi, y+l);
        }   

        auto calcBelow = [&](double mid) -> double
        {
          double total = 0;
          for (auto& sq: squares)
          {
            double x = sq[0];
            double y = sq[1];
            double l = sq[2];
            
            //计算 below 下面的 面积
            double overlap = min(mid - y, l);
            overlap = max(overlap, 0.0);
            total += l * overlap;
          }
          return total;
        };

        double totalArea = 0;
        for (auto& sq: squares)
        {
            double l = sq[2];
            totalArea += l * l;
        }

        double half = totalArea / 2.0;
        while (hi - lo > 1e-5)
        {
           double mid = lo + (hi - lo)/2;
           double below = calcBelow(mid);

            // 浮点数是连续的，mid 永远严格在 lo 和 hi 之间：
            // lo=3.0, hi=4.0, mid=3.5
            // lo = mid  → lo 变成 3.5   ✓ 区间缩小了一半
            // 每次 lo 或 hi 都精确变成 mid，区间每次缩小一半，天然收敛，不需要 ±1。
           if (below < half)
             lo = mid;
           else
             hi = mid;
            
        }

        return (lo + hi)/2.0;
    }
};