class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double lo = 1e9;
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
            
            //
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

           if (below < half)
             lo = mid;
           else
             hi = mid;
            
        }

        return (lo + hi)/2.0;
    }
};