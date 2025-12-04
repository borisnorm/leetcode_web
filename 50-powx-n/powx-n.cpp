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

        while (exp)
        {
           if (exp & 0x1)
           {
              result *= x;
           }

           x = x * x;
           exp >>= 1;
        }

        return result;
    }
};