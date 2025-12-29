class Solution {
public:
    int findComplement(int num) {
        unsigned int tmp = num;
        unsigned int mask = 0;

        while(tmp)
        {
           mask = (mask << 1) | 1;
           tmp >>= 1;
        }

        return ((~num) & mask);
    }
};