class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> num2freq;

        for(int num: nums)
          num2freq[num]++;

        using T = pair<int, int>;

        auto cmp = [](const T& a, const T& b){
            return a.second < b.second;
        };

        priority_queue<T, vector<T>, decltype(cmp)> pq;

        for (auto num2freq_pair: num2freq)
          pq.push(num2freq_pair);

        int maxFreqCnt = 0;
        int maxFreq = 0;

        while (!pq.empty())
        {
            int val = pq.top().second;
            if (val >= maxFreq)
            {
               maxFreq = val;
               maxFreqCnt += pq.top().second;
            }
            pq.pop();
            
        }

        return maxFreqCnt;
        
    }
};