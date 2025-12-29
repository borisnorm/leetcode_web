class Solution {
public:

   bool hasAlternatingBits(int n) {
       
       unsigned int x = n ^ (n >> 1); // 11111111111111
       return  ((x & (x+1)) == 0) ? true : false;
 
   }
/*
    bool hasAlternatingBits(int n) {
        
       int preDigit = -1;

        while (n)
        {
           int digit = (n & 0x1);
      
           if (preDigit != -1 && preDigit == digit)
              return false;

            preDigit = digit;       
        
           n = n >> 1;

        }

        return true;
    }
    */
};