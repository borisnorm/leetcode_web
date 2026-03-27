class Solution {
public:
     long long MOD = 1e9 + 7;
     int countGoodNumbers(long long n) {
        //每个位置独立选择，总方案 = 各位置方案数连乘。
        // even index 只能选 (0, 2, 4, 6, 8), 5个数
        // odd index  只能选 (2, 3, 5, 7) 4 个数

        // 12345, len 5, 5+1/2 = 3
        long long even_cnt = (n+1)/2;
        long long odd_cnt = n/2;

       return power2(5, even_cnt) * power2(4, odd_cnt) % MOD;
    }

   long long power2(long long base, long long exp)
   {
      long long res = 1;
      // 防止 base 太大
      base = base % MOD;

      while(exp > 0)
      { 
         // 8(2^3) 4(2^2)  2(2^1) 1(2^0)
         // 为了统一 奇偶次幂
         if (exp & 1)
           res = res * base % MOD;
         
         // 一个 base 就是 (base * base) * (base * base)
         base = base * base % MOD;

         //右移 一位, = exp / 2 
         exp = exp >> 1;
      }
      return res;
   }
};