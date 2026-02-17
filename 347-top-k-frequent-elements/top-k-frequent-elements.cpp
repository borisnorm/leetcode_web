class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0)
           return {};
        
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> num2freq;
        for (auto& num: nums)
          num2freq[num]++;
        
        using T = pair<int, int>;
        auto cmp = [](const T& a, const T& b){
             return a.second > b.second;  
        };

        priority_queue<T, vector<T>, decltype(cmp)> pq;
        for(auto& p: num2freq)
        {
           pq.push(p);
           if (pq.size() > k)
             pq.pop();
        }

        for (int i = 0; i < k; i++)
        {
            auto& p = pq.top();
            res.push_back(p.first);
            pq.pop();
        }

        return res;
    }
};

/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            if (nums.empty() || k <= 0)
              return {};
            int n = nums.size();
            vector<int> res;
            unordered_map<int, int> num2freq;
            for (auto& num: nums)
              num2freq[num]++;
            
            using T = pair<int, int>;
            vector<T> num2freq_vec;
            for (auto& p: num2freq)
              num2freq_vec.push_back(p);
            
            auto cmp = [](const T& a, const T& b){
                return a.second > b.second;
            };

            nth_element(num2freq_vec.begin(), num2freq_vec.begin() + k , num2freq_vec.end(), cmp);

            for (int i = 0; i < k; i++)
              res.push_back(move(num2freq_vec[i].first));
            
            return res;
    }
};
*/
/*
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
         if (nums.empty() || k <= 0)
           return {};
        
         vector<int> res;

        int n = nums.size();
        if (n < k)
          return {};
        // freq buckets counting
        // 1.count freq using unordered_map <key, freq>
        // 2.setup freq buckets vector idx = freq,  ele = vector<int> of key
        // 3.scan freq bucket from right to left and count k elements

        unordered_map<int, int> num2freq;
        for (int num: nums)
          num2freq[num]++;
        
        vector<vector<int>> freqBuckets(n+1);
        for (auto& [num, freq]: num2freq)
           freqBuckets[freq].push_back(num);
        
        int cnt = 0;
        for (int i = n; i >= 1 && cnt < k; i--)
        {
            //auto& freq_grp = freqBuckets[i];
            //for(auto& num: freq_grp)
            for (auto& num: freqBuckets[i])
            {
                res.push_back(num); 
                cnt++;
                if (cnt == k)
                  break;
            }
        }

        return res;
    }
};

*/


/*
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        // 频次 没有 0的说法 , 如果有, 那就是不存在
        unordered_map<int, int> num2freq;
        for (int num: nums)
          num2freq[num]++;
        
        int n = nums.size();

        // 基于 频率的桶
        //最大频次也就是 所有元素都是同一个, 共n个
        // 1-based 的 freq频率 bucket
        // 这是频次 bucket
        // 1, 2, 3, 4, 5, 6 
        //            5代表出现5次, 6代表出现6次
        vector<vector<int>> bucket(n+1);

        for (auto it: num2freq)
        {
           // 频次 作为 bucket 的 idx
           // 相同 高频的 不同 val 会作为 被bucket 的 content
           // 这些 val 被 unordered_map 过滤后已经是唯一的了
           bucket[it.second].push_back(it.first);
        }
        
        int cnt = 0;
        vector<int> res;
        // 这里 i >= 1, 频次不能是 0  否则没有意义了
        for (int i = n; i >= 1 && cnt < k; i--)
        {
            auto val_vec = bucket[i];

            //对于 val_vec 空的情况,  j < val_vec.size() 已经屏蔽了这种可能
            for (int j = 0; j < val_vec.size(); j++)
            {   
                res.push_back(val_vec[j]);
                cnt++;
                if (cnt == k)
                  break;
            }
        }

        return res;

    }

*/








    /*
    struct better{
      void operation(pair<int, int>& a, pair<int, int>& b) const {
          return a.second < b.second;
      }

    };
    */

  /*
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
           // push 消耗的是 当前 pq.size 的复杂度 也就是 n LogK, k= pq.size(), 不是 n
           // 例如已经有2个元素了, 它的幅度就是  log2,
           // 有3个元素的时候, 就是 log3
           // 由于一直在空着 size 的增长, 上限就是 K 了,所以 复杂度控制在 logK
           pq.push({it.first, it.second});

           // 小顶堆, 是将 小的元素 pop 出去是
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
   */