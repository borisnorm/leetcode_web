class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        
        if (n == 0)
          return {0};
        
        vector<int> res;

        long long base = 1;
        while(n)
        {
           int digit = n % 10;
           
           if (digit != 0)
             res.push_back(digit * base);

           n = n / 10;
           base = base * 10;
        }

        reverse(res.begin(), res.end());

        return res;
        
    }
};