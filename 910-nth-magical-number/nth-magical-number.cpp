class Solution {
public:

    long long gcd(int a, int b)
    {
       return b == 0 ? a : gcd(b, a % b);
    }
    int nthMagicalNumber(int n, int a, int b) {
         
         // a, b, ab
         // 能被 a, b 同时整除的 是最小公倍数
         const long long MOD = 1e9+7;
         long long lcm = (long long)a / gcd(a, b) * b;

         long long l = 1; 
         long long r = (long long)min(a, b) * n;

         while (l < r)
         {
           long long mid = l + (r-l)/2;
           // 整除 a 的个数 + 整除 b 的个数 - 能被 ab 同时整除的 个数
           long long cnt = mid / a + mid / b - mid / lcm;

           // 求 >= n 的 mid
           if (cnt >= n)
              r = mid;
            else
              l = mid + 1;
         }

         return l % MOD;
    }
};