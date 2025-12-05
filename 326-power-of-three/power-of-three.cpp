class Solution {
public:
    bool isPowerOfThree(int n) {

        if (n <= 0)
          return false;
          
        if (n == 1)
          return true;

        while (n)
        {
           int digit = n % 3; 
           if (digit != 0)
             return false;
           n = n / 3;
           if (n == 1)
             return true;
        }

        return true;
    }
};