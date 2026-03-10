class Solution {
public:
    struct worse
    {
       bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
             if (a.second == b.second)
               return a.first < b.first;
             return a.second > b.second;
       }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for (const string& word: words)
           mp[word]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>,  worse> pq;

        unordered_map<string, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
           pq.push(make_pair(it->first, it->second));

           if (pq.size() > k)
             pq.pop();    
        }

        vector<string> res;
        while (!pq.empty())
        {
          pair<string, int> pq_pair = pq.top();
          res.push_back(pq_pair.first);
          pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
