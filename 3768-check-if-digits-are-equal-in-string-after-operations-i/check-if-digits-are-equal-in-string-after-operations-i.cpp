class Solution {
public:
    bool hasSameDigits(string s) {
        
        int n = s.size();
        if (n < 2)
          return false;

        while (n > 2)
        {
           string num_str;
           for (int i = 0; i < n-1; i++)
           {
              for (int j = i + 1; j < n; j++)
              {
                 int digit = ((s[i] - '0') + (s[j] - '0')) % 10;
                 num_str.push_back(digit + '0');
                 //num_str.push_back(to_string(digit));
                 break;
              }
           }

           s = num_str;
           //n = s.size();
           n--;
        }

        return s[0] == s[1];
    }
};