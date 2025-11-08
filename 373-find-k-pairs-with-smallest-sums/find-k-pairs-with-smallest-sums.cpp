class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        auto cmp = [](const vector<int> &a, const vector<int> &b){
            return (a[0] + a[1]) > (b[0] + b[1]);  // a top, b new  if(false) a down b up 小顶堆
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < nums1.size(); i++)
          pq.push({nums1[i], nums2[0], 0});
        
        vector<vector<int>> res;

        while(!pq.empty() && k > 0)
        {
           vector<int> cur = pq.top();
           pq.pop();
           
           k--;

           int next_idx = cur[2] + 1;
           if (next_idx < nums2.size())
             pq.push({cur[0], nums2[next_idx], next_idx});
            
           res.push_back({cur[0], cur[1]});
             
        }

        return res;
    }
};