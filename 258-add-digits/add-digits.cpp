class Solution {
public:
    int addDigits(int num) {

       const int MAX_DIGIT = 9;
       
       while (num > MAX_DIGIT)
       {
          int sum = 0;
          while (num)
          {
            int digit = num % 10;
            sum += digit;
            num = num / 10;
          }
          num = sum;
       }

       return num;   
    }
};