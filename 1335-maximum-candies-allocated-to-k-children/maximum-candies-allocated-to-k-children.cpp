class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        //binary serach
        // n piles of candies
        // k children 

        long long sum = 0;
        for(int nCandies: candies)
          sum += nCandies;
        if (sum < k)
          return 0;

        int lo = 1;
        int hi = *max_element(candies.begin(), candies.end());
        int nCandies = 0;

        while (lo <= hi)
        {
           int mid = lo + (hi-lo)/2;

           if (canAllocate(candies, mid, k))
           {
              nCandies = mid;
              lo = mid + 1;
           }
           else
           {
              hi = mid - 1;
           }
        }

        return nCandies;
    }

    bool canAllocate(vector<int>& candies, long long nCandies, long long k)
    {
       long long nParts = 0;
       for (int candy: candies)
       {
          nParts += candy/nCandies;
          if (nParts >= k)
            return true;
       }

       return false;
    }
};