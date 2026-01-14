class Solution {
public:

    /*
    struct better{
      void operation(pair<int, int>& a, pair<int, int>& b) const {
          return a.second < b.second;
      }

    };
    */

    vector<int> topKFrequent(vector<int>& nums, int k) {

        if (nums.empty())
          return {};

        vector<int> res;
        int n = nums.size();

        unordered_map<int, int> num2freq;
        for (int i  = 0; i < n; i++)
          num2freq[nums[i]]++;

        //小顶堆是 大的元素 沉在 堆底  
        using T = pair<int, int>;
        auto cmp = [](const T& a, const T& b) {
              return a.second > b.second;   
        };
        priority_queue<T,  vector<T>, decltype(cmp)> pq;  //小顶堆

        for (auto it: num2freq)
        {
           pq.push({it.first, it.second});

           if (pq.size() > k)
             pq.pop();
        }

        int cnt = 0;
        while(!pq.empty() && cnt < k)
        {
           //栈顶是 freq 最小的元素, 然后随着 pop, freq 依次变大
           pair<int, int> top_pair = pq.top();
           pq.pop();

           res.push_back(top_pair.first);
           cnt++;    
        }

        return res;
    }
};