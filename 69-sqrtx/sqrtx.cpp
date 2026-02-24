class Solution {
public:
    int mySqrt(int x) {
       
        if (x < 2)
          return x;

        int l = 0;
        // 当 x = 1 的时候, r = 0 下面的循环也不走了, 直接返回 r = 0, 错误
        int r = x/2;

        while (l <= r)
        {
           long long mid = l + (r-l)/2;
           long long square = mid * mid;

           if (square < x)
             l = mid + 1;
           else if (square > x)
             r = mid - 1;
           else
             return mid;  
        }

        return r;
    }
};