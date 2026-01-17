class Solution {
public:
int makeTheIntegerZero(int num1, int num2) {

    if (num1 == 0)
      return 0;

    for (long long k = 0; k <= 60; k++)
    {
        long long x = num1 - k * num2;

        if (x < 0)
          continue;

        int pc = __builtin_popcountll(x);

        
        if (pc <= k && k <= x)
          return (int)k;
    }

    return -1;
}
  /*
    int makeTheIntegerZero(int num1, int num2) {
        
        // num1(i) = num1(i-1) - 2^i - num2 = 0;
        //           num1(i-1) - num2 = 2 ^i

        //  num1 = num1 - 2^(i+1) - num2;

        int cnt = 0;
        while(num1 != 0)
        {
        
           num1 = num1 - (2 * cnt > 0 ? 2 * cnt : 1) - num2;
           cnt++;

           if(num1 == 0) 
             return cnt; 
        }

        return -1;
    }
    */
};