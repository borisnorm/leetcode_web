class Solution {
public:
    int trailingZeroes(int n) {
       if (n <= 1)
         return 0;

       int tmp = n;
       long long divide = 5;
       int cnt = 0;
       while (tmp)
       {
          tmp = n/divide;
          divide = divide*5;
          cnt += tmp;
       }

       return cnt;
    }
};