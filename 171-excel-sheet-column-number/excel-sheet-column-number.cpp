class Solution {
public:
    int titleToNumber(string columnTitle) {
    
       if (columnTitle.empty())
         return 0;
        
       int n = columnTitle.size();
       long long base = 1;
       long long sum  = 0;

       for (int i = n - 1; i >= 0; i--)
       {
          int digit = columnTitle[i] - 'A' + 1;
          // digit 在 'Z' 时候没有 取余数 mode, 就是就是 digit = 26 - 1 + 1 = 26 
          // sum = 1 * 26 = 26;
          sum += base * digit;
          base = base * 26;
       }

       return sum;
    
    }


    /*
    int titleToNumber(string columnTitle) {
        if (columnTitle.empty())
          return 0;

        int n = columnTitle.size();

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
           int digit = columnTitle[i] - 'A' + 1;
           sum = sum * 26 + digit;           
        }

        return static_cast<int>(sum);
    }
    */
};