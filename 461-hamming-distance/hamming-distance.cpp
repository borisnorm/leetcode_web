class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;

        int cnt = 0;

        while (n)
        {
           n = n & (n-1);
           cnt++;
        }

        return cnt;
        
    }
};

/*
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        vector<int> dp(n+1, 0);
        
        for (int i = 1; i <= n; i++)
        {
           dp[i] = dp[i >> 1] + (i & 0x1);
        }

        return dp[n];
    }
};

*/


/*
class Solution {
public:
    int hammingDistance(int x, int y) {
        
        unsigned int n = (x ^ y);
        int cnt = 0;
        
        while (n)
        {
           cnt += n & 0x1;
           n >>= 1;
        }

        return cnt;
    }
};
*/