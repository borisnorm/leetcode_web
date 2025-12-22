class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int maxItemWeight = *max_element(weights.begin(), weights.end()); 
        int sum = 0;
        for (int weight: weights)
           sum += weight;

        int l = maxItemWeight;
        int r = sum;

        // d = sum /least weight of the ship;
        // least ship weight = sum / d,   where d 越大, least 越小
        while (l <= r)
        {
           int mid = l + (r - l)/2;

           if (canShip(weights, mid, days))
              r = mid - 1;
           else
              l = mid + 1;
        }

        return l;
    }

    bool canShip(vector<int> weights, int capacity, int days)
    {
       int day = 1;
       int cur = 0;

       for (int weight: weights)
       {
          if (cur + weight > capacity)
          {
             day++;
             cur = 0;
          }

          cur += weight;
       }

       return day <= days;
    }
};