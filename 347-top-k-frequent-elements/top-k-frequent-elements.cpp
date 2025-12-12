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
        unordered_map<int, int> mp;
        for (int i  = 0; i < n; i++)
          mp[nums[i]]++;

        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
              return a.second > b.second;   
        };

        priority_queue<pair<int, int>,  vector<pair<int, int>>, decltype(cmp)> pq;  //小顶堆

        for (auto& iter: mp)
        {
           pq.push(make_pair(iter.first, iter.second));

           if (pq.size() > k)
             pq.pop();
        }

        int cnt = 0;
        while(!pq.empty() && cnt < k)
        {
           pair<int, int> top_pair = pq.top();
           pq.pop();

           res.push_back(top_pair.first);
           cnt++;    
        }

        return res;
    }
};