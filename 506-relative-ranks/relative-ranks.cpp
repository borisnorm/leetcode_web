class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        vector<string> res(n);
        using T = pair<int, int>;
        auto cmp =[](const T& a, const T& b){
            return a.first < b.first;
        };
        
        priority_queue<T, vector<T>, decltype(cmp)> pq;

        for (int i = 0; i < n; i++)
          pq.push({score[i], i});
        
        int cnt = 0;
        while (!pq.empty())
        {
           auto it = pq.top(); 
           pq.pop();

           cnt++;

           if (cnt == 1)
             res[it.second] = "Gold Medal";
           else if (cnt == 2)
             res[it.second] = "Silver Medal";
           else if (cnt == 3)
             res[it.second] = "Bronze Medal";
           else 
             res[it.second] = to_string(cnt);
        }

        return res;
    }
};