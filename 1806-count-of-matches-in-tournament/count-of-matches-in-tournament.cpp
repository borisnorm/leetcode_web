class Solution {
public:
    int numberOfMatches(int n) {
        
        // n  teams
        int cnt = 0;
        while (n != 1)
        {
           if (n & 0x1)
           {
              cnt += (n-1)/2;
              n = (n-1)/2 + 1;
           }
           else
           {
              cnt += n/2;
              n = n/2;
           }
        }

        return cnt;
    }
};