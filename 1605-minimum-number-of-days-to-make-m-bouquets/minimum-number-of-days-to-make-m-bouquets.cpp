class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // [1, 2, 3, 10, 10]
        // m bouquets,  each has k adjacent flowers
        // 
       //mid 是我们猜测的天数，即"等了 mid 天之后，能不能做出 m 束花？"
        // 如果我们等了 days 天
       //bloomDay[i] <= days → 第 i 朵花已经开了
       //bloomDay[i] > days → 第 i 朵花还没开

       int n = bloomDay.size();
       if (1LL * m * k > n)
         return -1;
       
       int l = *min_element(bloomDay.begin(), bloomDay.end());
       int r = *max_element(bloomDay.begin(), bloomDay.end());
       
       while (l < r)
       {
          int mid = l + (r-l)/2;

          if (canMake(bloomDay, m, k, mid))
            r = mid;
          else
            l = mid + 1;
       }

       return l;
    }

    bool canMake(vector<int>& bloomDay, int m, int k, int days)
    {
        int cnt = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++)
        {

            if (bloomDay[i] <= days)
            {
                cnt++;

                if (cnt == k)
                {
                  bouquets++;
                  cnt = 0;
                }
            }
            else
            {
              cnt = 0;
            }
        }

        if (bouquets >= m)
          return true;
        
        return false;

    }
};