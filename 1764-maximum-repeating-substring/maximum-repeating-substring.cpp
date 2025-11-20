class Solution {
public:
    int maxRepeating(string sequence, string word) {
         
          if (sequence.empty() || word.empty())
            return 0;
        
         int n = sequence.size();
         int m = word.size();

         if (n < m)
           return 0;

         int ans = 0;

         for (int i = 0; i + m <= n; i++)
         {
            int cnt = 0;
            //while (i + (cnt + 1) * m <= n &&
             //      sequence.compare(i+cnt*m, m, word) == 0)
            for (int j = i; j <= n; j+=m)
            {
              if (sequence.compare(j, m, word) == 0)
                cnt++;
              else
                break;
            }
            ans = max(ans, cnt);
         }

         return ans;

    }
};