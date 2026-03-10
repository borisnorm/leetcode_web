class Solution {
public:
    char kthCharacter(int k) {
       int offset = 0;
       int len = 1;

       while (len < k)
         len *= 2;
       while(k > 1)
       {
          len /= 2;
          if (k > len)
          {
             k -= len;
             offset++;
          }
       }

       return 'a' + offset;
    }
};
/*
class Solution {
public:
    char kthCharacter(int k) {
        
        string s1  = "a";
        int totalLen = 0;
        // [0, k-1]
        // 5 6
        
        int loopCnt = 0;
        for (int i = 0; i < k && totalLen < k; i++)
        {
           totalLen = 1 << i;
           loopCnt = i;
        }

        for (int i = 0; i < loopCnt; i++)
        {
           string s2 = s1;

           for (int j = 0; j < s2.size(); j++)
           {
              s2[j] = s1[j] + 1;   
           }

           s1 += s2;
        }

        return s1[k-1];
    }
};

*/