class Solution {
public:
    string toHex(int num) {
        if (num == 0)
          return "0";
        
        string hex = "0123456789abcdef";
        string res;
        unsigned int n = num;
        while (n)
        {
           int cur = n & 0xf; // the lower 4 bit;
           res += hex[cur];
           n = n >> 4;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};