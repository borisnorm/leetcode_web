class Solution {
public:
    int countPrimes(int n) {
       if (n < 2)
         return 0;
       
       vector<bool> isPrime(n, true);
       //最小的质数是2
       //2 是最小的质数
       isPrime[0] = false;
       isPrime[1] = false;


       // 任何合数 x，一定存在一个质因子 p 满足 p ≤ √x。
       // 因此要把所有 < n 的合数都筛掉，只需要处理到 i ≤ √(n-1)（写成 i*i < n）。
       // 逆向使用这个定理 一定存在一个质因子 p 满足 p ≤ √x, 那么这个X 就是 合数
       //   p 是 i
       //   j = i * i 或是 i * i + k * i 是 x, 要被过滤的数 要 < n
       //   那么 i 的 i * i 也要 < n, 否则 j 都无法计算了
       // 
       // 我们筛除的是 合数, 最后留下的就是质数
       for (long long i = 2; i * i < n; i++)
       {
           // 未来的数已经被设置为 非 prime 了不用再查了
           if (!isPrime[i])
             continue;
            
           //所有小于 i * i 的 i 的倍数，都已经被更小的质数筛掉了，所以从 i * i 开始才有意义。
           //for (int j = 2 * i; j < n; j += i) 逻辑上是对的，但效率很差，而且会重复做无用功
           //  j = 2 * i
           //  j = 3 * i  // j (2 * i) += i = 3 * i
           //  j = 4 * i  // j (3 * i) += i = 4 * i
           //  j = 5 * i

           //如果 k < i，那么 k * i 一定在 i * i 之前，并且已经被 k 处理过。
           for (long long j = i * i; j < n; j += i)
           {
              isPrime[(int)j] = false;
           } 
       }

       int cnt = 0;
       for (int i = 2; i < n; i++)
       {
          if (isPrime[i])
            cnt++;
       }
       return cnt;
    }
};