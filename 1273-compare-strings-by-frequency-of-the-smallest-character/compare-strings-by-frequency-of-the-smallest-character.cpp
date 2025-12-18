class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        int m = words.size();
        vector<char> fwordFreq(m, 0);

        int idx = 0;
        for (string word : words)
        {
           int charfreq[26] = {0};
           for (int i = 0; i < word.size(); i++)
             charfreq[word[i]-'a']++;
            
           int minFreq = INT_MAX;
           for (int i = 0; i < 26; i++)
           {
              if (charfreq[i] != 0 && charfreq[i] < minFreq)
              {
                 minFreq = charfreq[i];
                 break;
              }
           }

           fwordFreq[idx++] = minFreq;
        }

        int n = queries.size();
        vector<int> fqueryFreq(n, 0);
        int qidx = 0;
        
        for (string query: queries)
        {
           int charfreq[26] = {0};
           for (int i = 0; i < query.size(); i++)
             charfreq[query[i]-'a']++;

           int minFreq = INT_MAX;
           for (int i = 0; i < 26; i++)
           {
              if (charfreq[i] != 0 && charfreq[i] < minFreq)
              {
                 minFreq = charfreq[i];
                 break;
              }
           }

           fqueryFreq[qidx++] = minFreq;
        }

        vector<int> res;
        for (int i = 0; i < fqueryFreq.size(); i++)
        {
            int cnt = 0;
            for (int j = 0; j < fwordFreq.size(); j++)
            {
               if (fwordFreq[j] > fqueryFreq[i])
                 cnt++;
            }

            res.push_back(cnt);
        }

        return res;
    }
};