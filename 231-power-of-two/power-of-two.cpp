class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n <= 0)
          return false;

        if (n == 1)
          return true;
        
        while (n > 1 )
        {
           int remain = n%2;   // 16 / 8 / 4/ 2 / 1
           if (remain != 0)
              return false;
           n = n /2;
        }

        return true;
    }
};