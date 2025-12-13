class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        int sign = 1;
        int res = 0;

        int i = 0;
        while (i < n && s[i] == ' ')
          i++;    
        if (i == n)
          return 0;

        if (s[i] == '-')
        {
          sign = -1;
          i++;
        }
        else if (s[i] == '+')
        {
          i++;
        }
        if (i==n)
          return 0;

        while (i < n && '0' <= s[i] && s[i] <= '9')
        {
            int digit = s[i] - '0';
            
            // 4. 溢出检测
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            /*
            if (sign > 0)
            {
              if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7))
                return  INT_MAX;
            }
            else
            {
              if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 8)) 
                return  INT_MIN;
            }
            */

            res = res*10 + digit;
            
           i++;
        }

        return (int) (res * sign);
        
    }
};