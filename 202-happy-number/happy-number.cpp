class Solution {
public:

    int get(int n)
    {
       int sum = 0;
       while (n)
       {
          int digit = n%10;
          sum += digit * digit;
          n = n / 10;
       }

       return sum;
    }

    bool isHappy(int n) {
       if (n == 0)
         return false;

        int slow = get(n);
        int fast = get(get(n));

        while (fast != 1 && slow != fast)
        {
           slow = get(slow);
           fast = get(get(fast)); 
        }

        return (fast == 1) ? true : false;
    }
};