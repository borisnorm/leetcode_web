class Solution {
public:
    bool isPalindrome(int x) {
       if (x < 0 || (x%10 ==0 && x!= 0))
         return false;
       
       int res = 0;
       while (x > res)
       {
          int digit = x % 10;
          x = x / 10;

          res = res * 10 + digit;
       } 

       // even res == x      1221  x = 12  res = 12;
       // odd  res == x/10  12321  x = 12  res = 123
       if (x == res || x == res/10)
         return true;
       
       return false;

    }
};

/*
class Solution {
public:
    bool isPalindrome(int x) {
        vector<char> digit_arr;
        int tmp = x;
        int digit_cnt;
        int idx = 0;
        long long sum = 0;

        if (x < 0)
            return false;
        if (x%10==0 && x!=0)
          return false;

        while (tmp != 0) {
            digit_arr.push_back(tmp % 10 + '0');
            tmp = tmp / 10;
        }

        digit_cnt = digit_arr.size();

        for (idx = (digit_cnt - 1); idx >= 0; idx--) {
            sum = sum * 10 + (digit_arr[idx] - '0');
        }

        return (sum == x) ? true : false;
    }
};
*/