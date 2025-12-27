class Solution {
public:
    string reverseStr(string s, int k) {
        
        int n = s.size();
        if (n == 0 || k == 0)
          return s;

        if (n < k)
        {
          reverse(s.begin(), s.end());
          return s;
        }

        bool isReversed = false;
        for (int i = 0; i < n; i+=k)
        {
            if (!isReversed)
            {
               if (i + k - 1 < n)
               {
                 reverse(s.begin()+i, s.begin()+i+k);
               }
               else
               {
                 reverse(s.begin()+i, s.end());
               }
               isReversed = true;
            }
            else
            {
               isReversed = false;
            }
        }

        return s;
    }
};