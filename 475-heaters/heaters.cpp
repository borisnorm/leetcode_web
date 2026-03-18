class Solution {
public:
    bool canCover(vector<int>& houses, vector<int>& heaters, int r) {
      for (int h: houses)
      {
        auto it = lower_bound(heaters.begin(), heaters.end(), h);

        bool covered = false;

        if (it != heaters.end() && *it - h <= r)
          covered = true;

        if (it != heaters.begin())
        {
          --it;
          if (h - *it <= r)
            covered = true;
        }

        if (!covered)
          return false;
      }  

      return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
      sort(heaters.begin(), heaters.end());
      int lo = 0;
      int hi = 2e9;

      while (lo < hi)
      {
         int mid = lo + (hi-lo)/2;
         if (canCover(houses, heaters, mid))
           hi = mid;
         else
           lo = mid + 1;
      }

      return lo;
    }

};