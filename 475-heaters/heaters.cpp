class Solution {
public:
    bool canCover(vector<int>& houses, vector<int>& heaters, int radius) {
      for (int h: houses)
      {
        // 在已排序的 heater数组中，第一个 >= target (house)的 heater 的位置
        // 找一个 heater >= 当前的这个 house
        auto it = lower_bound(heaters.begin(), heaters.end(), h);

        bool covered = false;
        // it == heaters.end()   → 所有heater都在h左边，只看左侧
        // it == heaters.begin() → 所有heater都在h右边，只看右侧
        if (it != heaters.end() && *it - h <= radius)
          covered = true;

        if (it != heaters.begin())
        {
          //it 现在指向的是右侧第一个 >= h 的heater，要找左侧heater就必须往左移一步。
          // 左边的 it 是最后一个  < h 的 heater
          --it;
          if (h - *it <= radius)
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
      //二分的是暖气的半径 r（一个抽象的数值），不是任何具体的 house 或 heater 的下标。
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