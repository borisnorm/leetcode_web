class Solution {
public:

    int maxFrequencyElements(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0)
          return 0;

        unordered_map<int, int> num2freq;

        int maxFreq = 0;
        int maxFreqCnt = 0;
    
        for (int num: nums)
        {
            // individual
            num2freq[num]++;
            int f = num2freq[num];

            // maxFreq
            if (f > maxFreq)
            {
               maxFreq = f;
               maxFreqCnt = f;
            }
            else if (f == maxFreq)
            {
            // aggregate
                maxFreqCnt += f;
            }
        }

        return maxFreqCnt;
    }


   // [2, 2, 3, 3, 2]

    /*
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
    */
};