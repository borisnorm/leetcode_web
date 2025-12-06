class Solution {
public:
    string convertToBase7(int num) {
          
        string res;
        if (num == 0)
          return  "0";

        int sign = (num < 0) ? -1 : 1;
        int  n = abs(num);
        while (n)
        {
          res += to_string(n % 7);
          n = n/7;
        }
        reverse(res.begin(), res.end());
        if (sign < 0)
          res = "-" + res;

        return res;
    }
};