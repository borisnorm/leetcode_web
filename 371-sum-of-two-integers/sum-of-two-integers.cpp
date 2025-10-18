class Solution {
public:
    int getSum(int a, int b) {
       // 01
       // 10
       // --
       // 11

       // 10 
       // 11
       // --
       // 101
       
       while (b!=0)
       {
          int carry = (a&b) << 1;
          a = a ^ b;
          b = carry;
       }

       return a;

    }
};