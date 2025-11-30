class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) return 0;
        
        priority_queue<int> pq;

        for (int w: stones)
          pq.push(w);

        while (pq.size() >= 2)
        {
          int x = pq.top(); pq.pop();
          int y = pq.top(); pq.pop();

          if (x > y)
            pq.push(x - y);
        
          // 相等的时候, 2块都取出, 相当于 互相抵消了
        }

        if (pq.empty())
          return 0;
        
        return pq.top();

    }
};