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