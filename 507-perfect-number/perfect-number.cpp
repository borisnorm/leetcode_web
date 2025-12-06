class Solution {
public:
    bool checkPerfectNumber(int num) {
        
         if (num <= 1)
           return false;

         int sum = 1;   // 默认因为 需要是  1 才可以

         for (int i = 2; (long long)i * i <= num; i++)
         {
            // sum += divisor + remaining(num/i) 
            if (num % i == 0)
            {
               int remain = num / i;
               sum += i + ((remain != i) ? remain : 0);
            }
         }

         return (num == sum) ? true : false;
    }
};