class Solution {
public:
    string findValidPair(string s) {
         int freq[10] = {0};

         for (char c : s)
          freq[c-'0']++;

         int n = s.size();
        
         if (n < 2)
           return "";
        
         string res;

         for (int i = 0; i + 1 < n; i++)
         {
             int digit_1 = s[i] - '0';
             int digit_2 = s[i+1] - '0';

             if (digit_1 != digit_2 && freq[digit_1] == digit_1 && freq[digit_2] == digit_2)
             {
                res += s[i];
                res += s[i+1];
                return res;
             }
         }
         
         return res;
    }
};