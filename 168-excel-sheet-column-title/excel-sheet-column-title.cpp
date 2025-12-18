class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string res;

        if (columnNumber == 0)
          return "0";

        if (columnNumber < 0)
          return res;

        long long n = columnNumber;
        while (n)
        {
           char digit = ((n-1) % 26) + 'A';
           // char digit = (columnNumber % 26) + 'A';
           res += digit;
           n = (n-1)/26;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};