class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> char2freq;
        for (char c : s) char2freq[c]++;

        using It = unordered_map<char, int>::iterator;
        auto cmp = [](const It& a, const It& b) {
            return a->second < b->second; // freq 大的优先
        };

        priority_queue<It, vector<It>, decltype(cmp)> pq(cmp);

        for (auto it = char2freq.begin(); it != char2freq.end(); ++it)
            pq.push(it);

        string res;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            res.append(it->second, it->first);
        }
        return res;
    }
};


/*
class Solution {
public:
    string frequencySort(string s) {
        
         unordered_map<char, int> char2freq;
         using T = unordered_map<char, int>::iterator;

         auto cmp = [](const T& a, const T& b){
              return a->second < b->second;
              //return a.second < b.second;
         };

         priority_queue<T, vector<T>, decltype(cmp)> pq;
         for (char c: s)
           char2freq[c]++;
        
         //for (auto& it : char2freq)
         for (auto it = char2freq.begin(); it != char2freq.end(); it++)
           pq.push(it);

         string res;
         while (!pq.empty())
         {
            auto& it = pq.top();
            pq.pop();

            int cnt = it->second;
            int c   = it->first;

            for (int i = 0; i < cnt; i++)
              res += c;
         }

         return res;
    }
};
*/