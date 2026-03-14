class Solution {
public:
    int numSteps(string s) {
    
        int n = s.size();
        int bit = 0;
        int carry = 0;
        int step = 0;

        // keep s[0], s[0] == '1'
        // 循环只处理 s[0] 以外的所有位（i > 0），目标是把这些位全部消除掉
        for (int i = n - 1; i > 0; i--)
        {
           bit = s[i]- '0' + carry;

           // bit = 0 or 2
           if (bit % 2 == 0)
           {
             step++;
             carry = bit/2;
           }   
           else
           {
              // odd +1, step+1,  changed to even, even/2, step+1
              step += 2;
              // bit is odd numb,  +1, 必然carry = 1;
              carry = 1;
           }
        }

        step += carry;

        return step;
    }
};
/*
// 超时
class Solution {
public:
    int numSteps(string s) {
        
        long long num = 0;
        for (char c: s)
        {
           num = num << 1 | (c-'0');
        }

       int step = 0;
        while (num != 1)
        {
           if ((num % 2) == 0)
             num /= 2;
           else
             num += 1;

           step++;
        }
        return step;
    }
};
*/