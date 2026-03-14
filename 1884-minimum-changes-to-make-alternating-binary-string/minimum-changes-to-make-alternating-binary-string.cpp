class Solution {
public:
    int minOperations(string s) {
       
       int n = s.size();
       int ops1 = 0;
       for (int i = 0; i < n; i++)
       {
          char expected =  (i & 0x1) ? '1' : '0';
          if (s[i] != expected)
            ops1++;
       }

       // cost_b = n - cost_a（互补关系）
       int ops2 = n - ops1;

       return min(ops1, ops2);
    }
};

/*
class Solution {
public:
    int minOperations(string s) {

        // chane 1 frst
        // not change 1first
        int n = s.size();
        //10
        int ops1 = 0;
        for (int i = 0; i < n; i++)
        {
           if ((i & 0x1) && s[i] != '0')
             ops1++;
           else if (!(i & 0x1) && s[i] != '1')
             ops1++;
        }

        // 01
        int ops2 = 0;
        for (int i = 0; i < n; i++)
        {
           if ((i & 0x1) && s[i] != '1')
             ops2++;
           else if (!(i & 0x1) && s[i] != '0')
             ops2++;
        }

        int minCnt = min(ops1, ops2);

        return minCnt;
    }
};

*/