class Solution {
public:
    int nextBeautifulNumber(int n) {
        // smallest numberically balanced number, strictly greater than n

        // if (digit == digit2freq[digit])
        int num = 0;
        for (int i = n + 1; i < INT_MAX; i++)
        {
            if (isBeatifulNumber(i))
            {
               num = i;
               break;
            }
        }

        return num;
    }

    bool isBeatifulNumber(int n)
    {
       int digit2freq[10] = {};
       
       string n_str = to_string(n);
       for (char c : n_str)
         digit2freq[c-'0']++;

       for (int d = 0; d <= 9; d++)
       {
          // 必须跳过没有出现过的数字
          if (digit2freq[d] != 0 && digit2freq[d] != d)   
            return false;
       }

       //出现 0 必然错误
       if (digit2freq[0] != 0)
         return false;

       return true;         
    }
};