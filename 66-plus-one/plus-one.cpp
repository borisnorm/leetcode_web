class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty())
          return {};

        int n = digits.size();
        int sum = 0;
        int carry = 0;
        int addon = 0;

        for (int i = n - 1; i >= 0; i--)
        {   
            addon = (i == (n-1)) ? 1 : 0;   
            sum = digits[i] + carry + addon;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry)
        {
          digits.resize(n+1);

          for (int i = n; i >= 1; i--)
            digits[i] = digits[i-1];

          digits[0] = carry;
        }

        return digits;

    }
};