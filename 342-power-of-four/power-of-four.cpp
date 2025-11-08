class Solution {
public:
    bool isPowerOfFour(int n) {

        if (n <= 0)
          return false;

        while (n)
        {
           if (n%4 != 0)
             break;
           n = n / 4;
        }
        
        return (n==1);
    }
};