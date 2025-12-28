class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int text_freq[26];

        for (char c : text)
          text_freq[c-'a']++;

        int freq = INT_MAX;
        string s = "balloon";
        int n = s.size();

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
          int idx = s[i] - 'a';
          if (text_freq[idx] == 0)
            break;    

          text_freq[idx]--;

          if (i == n-1)
          {
             cnt++;
             i = -1;
          }


        }

        return cnt;
        
    }
};