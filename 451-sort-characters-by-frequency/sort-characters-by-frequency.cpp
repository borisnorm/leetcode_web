class Solution {
public:
    string frequencySort(string s) {
       
       unordered_map<char, int> char2freq;
       
       for (char c: s)
         char2freq[c]++;
    
       int n = s.size();
       // convert 0-based to 1-based
       // 因为 统计的频率都是 1 开始的
       vector<string> buckets(n+1);
       for (auto & [c, freq]: char2freq)
       {
          buckets[freq].append(freq, c);
       }

       string res;
       for (int i = n; i >= 0; i--)
       {
          if (!buckets[i].empty())
            res += buckets[i];
       }

       return res;
 
    }
    

    /*
    string frequencySort(string s) {
        
         unordered_map<char, int> char2freq;
         using T = unordered_map<char, int>::iterator;

         auto cmp = [](const T& a, const T& b){
              return a->second < b->second;
              //return a.second < b.second;
         };

         // priority queue 默认是大顶堆
         priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);
         for (char c: s)
           char2freq[c]++;
        
         // 错误的, for rang 对于 map 而言, 返回的 kv pair 的 键值对, 不是 iterator
         //for (unordered_map<char, int>::iterator it : char2freq)
         //  pq.push(it);

         for (auto it = char2freq.begin(); it != char2freq.end(); it++)
           pq.push(it);

         string res;
         while (!pq.empty())
         {
            // 不能 &, pop 后 it 引用会被 干掉
            //auto& it = pq.top();
            auto it = pq.top();
            pq.pop();

            // append 操作可以替代 循环;
            //res.append(it->second, it->first);
            int cnt = it->second;
            int c   = it->first;

            for (int i = 0; i < cnt; i++)
              res += c;
         }

         return res;
    }
    */
};