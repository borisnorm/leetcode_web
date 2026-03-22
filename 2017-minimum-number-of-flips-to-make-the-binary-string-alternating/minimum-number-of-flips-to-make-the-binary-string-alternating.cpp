class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;

        int diff1 = 0;
        int diff2 = 0;
        int minFlip = INT_MAX;

        int l = 0;

        for (int r = 0; r < ss.size(); r++)
        { 
           //'01010101'
           char expected1 = (r % 2 == 0) ? '0' : '1';
           //'10101010'
           char expected2 = (r % 2 == 0) ? '1' : '0';

           if (ss[r] != expected1)
             diff1++;

           if (ss[r] != expected2)
             diff2++;

           if (r - l + 1 > n)
           {
              char leftExpected1 = (l % 2 == 0) ? '0' : '1';
              char leftExpected2 = (l % 2 == 0) ? '1' : '0';

              if (ss[l] != leftExpected1)
                diff1--;
              
              if (ss[l] != leftExpected2)
                diff2--;

               l++;
           }

           if (r - l + 1 == n)
             minFlip = min(minFlip, min(diff1, diff2));
        }

        return minFlip;
    }
};