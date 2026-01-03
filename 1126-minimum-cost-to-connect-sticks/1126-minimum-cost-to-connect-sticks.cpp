class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        if (n <= 1)
          return 0;
        
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        long long cost = 0;

        while (pq.size() > 1)
        {
           int a = pq.top();
           pq.pop();
           int b = pq.top();
           pq.pop();

           int sum = a + b;
           cost += sum;

           pq.push(sum);
        }

        return cost;
    }
};