class Solution {
public:
    double myPow(double x, int n) {
        
        long long exp = n;

        if (exp < 0)
        {
           exp = 0 - exp;
           x = 1.0/x;
        }

        double result = 1.0;

        //x^n = x^(n/2) * x^(n/2) * x^(n%2)
        while (exp)
        {
           if (exp & 0x1)
              result = result * x;    // 当 exp (n) 是一个奇数的时候, 第一次运行的时候, result 就被赋予了 x, 作为 x 的奇数项 乘进去

           x = x * x;  // x(x^2) * x(x^2) = x^4
           exp >>= 1;  // exp = exp/2
        }

        return result;
    }
};