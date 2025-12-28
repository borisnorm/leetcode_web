class Solution {
public:
    int balancedStringSplit(string s) {
        
        int split_cnt = 0;
        int n = s.size();

        int l_cnt = 0;
        int r_cnt = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
           if (s[i] == 'L')
             l_cnt++;
           else if (s[i] == 'R')
             r_cnt++;

           if (l_cnt == r_cnt)
           {
              l_cnt = 0;
              r_cnt = 0;

              int len = i - start + 1;
              start = i + 1;
              split_cnt++;
           }
        }

        return split_cnt;
    }
};