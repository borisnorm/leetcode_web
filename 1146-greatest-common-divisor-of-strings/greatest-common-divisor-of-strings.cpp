class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        int m = str1.size();
        int n = str2.size();

        if ((str1 + str2) != (str2 + str1))
          return "";
        
        int g = gcd(m, n);

        return str1.substr(0, g);
    }

    int gcd(int a, int b)
    {
       while (b != 0)
       {
          int t = a % b;
          a = b;
          b = t;
       }

       return a;
    }

};