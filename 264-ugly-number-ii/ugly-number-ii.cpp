class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;

        int product2 = 1;
        int product3 = 1;
        int product5 = 1;

        vector<int> ugly(n+1);

        int p = 1;

        while (p <= n)
        {
          int min = std::min({product2, product3, product5});

          ugly[p] = min;
          p++;
         
          if (min == product2)
          {
             product2 = 2 * ugly[p2];
             p2++;
          }

          if (min == product3)
          {
             product3 = 3 * ugly[p3];
             p3++;
          }

          if (min == product5)
          {
            product5 = 5 * ugly[p5];
            p5++;
          }
        }

        return ugly[n];
    } 
};