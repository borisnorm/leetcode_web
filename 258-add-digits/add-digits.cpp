class Solution {
public:
    int addDigits(int num) {

       int sum = num;
       const int MAX_DIGIT = 9;
       
       while (sum > MAX_DIGIT)
       {
          int n = sum;
          
          sum = 0;
          while (n)
          {
            int digit = n % 10;
            sum += digit;

            n = n / 10;
          }
       }

       return sum;   
    }
};