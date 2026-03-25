class Solution {
public:
    int countDigitOne(int n) {
        long long res = 0;
        long long factor = 1;

        while(factor <= n)
        {
          // 3159
          long long higher = n / (factor * 10);
          long long cur  = (n/factor) % 10;
          long long lower  =  n % factor; 

          if (cur == 0)
          {
             // cur = 0, higher 要少取1位, higher - 1, 例如7059
             // [0, higher-1]
             res += higher * factor;
          }
          else if (cur == 1)
          {
             // higher 固定    1 * [0, lower]
             // higher 不固定  [0, higher-1]  
             res += higher * factor + lower + 1;
          }
          else
          { 
             // > 1, 那就是 [0, higher] 可以 count higher 那位了 了
             res += (higher + 1) * factor;
          }

          factor *= 10;
        }

        return res;
    }
};