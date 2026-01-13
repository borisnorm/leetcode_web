class Solution {
public:
    int findNthDigit(int n) {
        
        long long N = n; 
        long long base = 1;
        long long cnt = 9;
        long long len = 1;

        long long sum = 0;
        while (N > cnt * len)
        {
        
           N = N - (len * cnt);
           //base = 10 * base;
        
           len++;
           cnt = cnt * 10;
           base = base * 10;
        }


        int num = base + (N-1)/len;
        int idx = (N-1) % len;

        string s = to_string(num);

        return s[idx] - '0'; 
    }
};