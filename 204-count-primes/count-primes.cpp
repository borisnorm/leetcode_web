class Solution {
public:
    int countPrimes(int n) {
       if (n <=2)
         return 0;
    
       vector<bool> isPrime(n, true);
       isPrime[0] = false;
       isPrime[1] = false;

       for (long long i = 2; i * i < n; i++)
       {
           if (!isPrime[i])
             continue;
            
           //所有小于 i * i 的 i 的倍数，都已经被更小的质数筛掉了，所以从 i * i 开始才有意义。
           //for (int j = 2 * i; j < n; j += i) 逻辑上是对的，但效率很差，而且会重复做无用功
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