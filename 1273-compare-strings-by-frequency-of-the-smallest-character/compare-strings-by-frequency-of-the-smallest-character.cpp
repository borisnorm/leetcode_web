class Solution {
public:

    int f(const string& s)
    {
       char minChar = 'z';
       int cnt = 0;
       
       for (char c: s)
       {
          if (c < minChar)
          {
             minChar = c;
             cnt = 1;
          }
          else if (c == minChar)
            cnt++;
       }

       return cnt;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wf;
        for (auto & word: words)
        {
           wf.push_back(f(word));
        }

        // sort 是为了 upper_bound 的 二分法
        sort(wf.begin(), wf.end());

        vector<int> res;

        for (auto & query : queries)
        {
            int fq = f(query);

            auto it = upper_bound(wf.begin(), wf.end(), fq);
            
            // it > fq 的 iterator, wf.end(), 是数组的 最后一个空位
            // wf [ 1, 2, 3, 4, 5, wf.end()]
            // wf.end()-it, 就是比 fq 大的元素的个数
            res.push_back(wf.end()-it);
        }

        return res;

    }
/*
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        int m = words.size();
        vector<int> fwordFreq(m, 0);

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
    */
};