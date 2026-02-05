class Solution {
public:
    bool checkValidString(string s) {
        if (s.empty())
          return 0;

        int minLeft = 0;  // minimum possible '(' count
        int maxLeft = 0;  // maximum possible '(' count

        for (char c: s)
        {
           if (c == '(')
           {
              minLeft++;
              maxLeft++;
           }
           else if (c == ')')
           {
              minLeft--;
              maxLeft--;
           }
           else if (c =='*')
           {
              minLeft--;   // treat '*' as ')'
              maxLeft++;   // treat '*' as '('
           }

           if (maxLeft < 0)   // treat '*' as '('
             return false;

           if (minLeft < 0)
             minLeft = 0;   // '(' count can't be negative

           // 等效
           //lo = max(lo, 0);
        }
       return minLeft == 0;

    }
};