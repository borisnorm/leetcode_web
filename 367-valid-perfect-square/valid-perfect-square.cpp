class Solution {
public:
    bool isPerfectSquare(int num) {
         if (num < 0)
           return false;
         if (num <= 1)
           return true;
        
         int l = 0;
         int r = num;
         while (l <= r)
         {
            long long  mid = l + (r-l)/2;
            long long product = mid * mid;

            if (product < num)
              l = mid + 1;
            else if (product > num)
              r = mid - 1;
            else
              return true;
         }

         return false;
    }
};