class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l < r)
        {
           int mid = l + (r -l)/2;

           long long hours = 0;
           for (auto p: piles)
           {
              //hour = ceil(p/mid) = p + mid - 1 / mid;
              hours += (p + mid - 1)/mid;
           }

           if (hours <= h)
             //这里用的是「找最小可行值（lower_bound）」的二分模板，
             r = mid;
           else
             l = mid + 1;         
        }

        return l;
    }
};