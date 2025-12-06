class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 0)
          return 0;

        int row = 0;
        while (n >= 0)
        {
           n = n - row;
           if ( n < 0)
             break;

           row++;   
        }

        return row - 1;

    }
};