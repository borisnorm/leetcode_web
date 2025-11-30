class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c: s)
          freq[c]++;
        
        int n = s.size();
        int maxDupCnt = (n+1)/2;
        for (auto &p: freq)
        {
           if (p.second > maxDupCnt)
             return "";
        }

        priority_queue<pair<int, char>> pq;
        for (auto &p: freq)
          pq.push({p.second, p.first});

        string res;
        while (pq.size() > 1)
        {
          auto [cnt1, c1] = pq.top(); pq.pop();
          auto [cnt2, c2] = pq.top(); pq.pop();

          res += c1;
          res += c2;

          cnt1--;
          cnt2--;

          if (cnt1 > 0)
            pq.push({cnt1, c1});
          if (cnt2 > 0)
            pq.push({cnt2, c2});
        }

        if (!pq.empty())
        {
           auto [cnt, c] = pq.top();
           if (cnt > 1)
             return "";
           res += c;
        }

        return res;
    }
};