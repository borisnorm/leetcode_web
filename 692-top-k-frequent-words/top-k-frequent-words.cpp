class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> word2freq;

        for (const string& word: words)
           word2freq[word]++;
        
        using T = pair<string, int>;
        // top K 使用 min-heap 小顶堆
        auto cmp = [](const T& a, const T& b){
            if (a.second == b.second)
              return a.first < b.first;
            return a.second > b.second;
        };
        priority_queue<T, vector<T>,  decltype(cmp)> pq;
        for (auto [word, freq]: word2freq)
        {
           pq.push({word, freq});

           if (pq.size() > k)
             pq.pop();    
        }

        vector<string> res;
        while (!pq.empty())
        {
          auto [word, freq] = pq.top();
          res.push_back(word);
          pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
/*
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

*/