class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        int sign = 1;
        
        int i = 0;
        while (i < n && s[i] == ' ')
          i++;
        if (i == n)
          return 0;
        
        if (i < n && (s[i]=='+' || s[i]=='-'))
        {
          sign = (s[i]=='-') ? -1 : 1;
          i++;
        }
        if (i == n)
          return 0;

        long long res = 0;
        while (i < n && '0' <= s[i] && s[i] <='9')
        {
           int digit = s[i] - '0';
           res = res * 10 + digit;

            //if (res * sign > INT_MAX) return INT_MAX;
           // if (res * sign < INT_MIN) return INT_MIN;

        
                        // ✅ 提前检查：在乘以sign之前就检查边界
            if (sign == 1 && res > INT_MAX)
                return INT_MAX;
            if (sign == -1 && res > (long long)INT_MAX + 1)  // INT_MIN的绝对值
                return INT_MIN;
         
          /*
           if (sign > 0)
             if (res > INT_MAX)
               return INT_MAX;
            else
              if (res > (long long)INT_MAX + 1)
                return INT_MIN;
            */
            i++;
        }

        return (int) (res * sign) ;
    }
};

/*
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        int sign = 1;


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

        int res = 0;
        while (i < n && '0' <= s[i] && s[i] <= '9')
        {
            int digit = s[i] - '0';
            
            // 4. 溢出检测
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            
            //if (sign > 0)
            //{
            //  if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7))
            //    return  INT_MAX;
           // }
            //else
           // {
            //  if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 8)) 
            //    return  INT_MIN;
           // }
            

            res = res*10 + digit;
            
           i++;
        }

        return (int) (res * sign);
        
    }
};
*/