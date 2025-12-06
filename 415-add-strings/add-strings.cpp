class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;

        int m = num1.size() - 1;
        int n = num2.size() - 1;

        int carry = 0;
        int sum   = 0;
        int digit = 0;
        int num1_val = 0;
        int num2_val = 0;

        while (m >= 0 || n >= 0 || carry)
        {
           num1_val = (m >= 0) ? num1[m] - '0' : 0;
           num2_val = (n >= 0) ? num2[n] - '0' : 0;
           
           sum  = num1_val + num2_val + carry;
           carry = sum / 10; 
           digit = sum % 10;
           res += to_string(digit);

           m--;
           n--;
        }

        reverse(res.begin(), res.end());
    
        return res;
    }
};