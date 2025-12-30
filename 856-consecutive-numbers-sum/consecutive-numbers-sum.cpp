class Solution {
public:
    int consecutiveNumbersSum(int n) {
        
        //  k 是第几项
        // n =  x + ( x + 1) + (x + 2) ... (x + k -1)
        //   =  kx + 1+2..(k-1)
        //   =  kx + (1 + k-1)*(k-1)/2
        //   =  kx + k(k-1)/2

        //  求这个的 x 是否存在 
        //  x =  (n - k(k-1)/2)/k
        // n - k(k-1)/2 > 0  ==> n > k(k-1)/2
        // remain = n - k(k-1)/2

        long long res = 0;
        for (long long k = 1; k * (k - 1)/2 < n; k++)
        {
            long long remain = n - k * (k - 1)/2;
            if (remain % k == 0)
              res++;
        }
        return res;
    }
};