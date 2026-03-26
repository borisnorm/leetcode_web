class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
                       //val, list_idx, ele_idx
        using T = tuple<int, int, int>;
        /*
        // 正确
        auto cmp = [](const T& a, const T& b){
           return  get<0>(a) > get<0>(b);
        };
         priority_queue<T, vector<T>, decltype(cmp)> pq;
        */
         priority_queue<T, vector<T>, greater<T>> pq;
       
        
        int n = nums.size();
        int curMax = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }

        vector<int> ans = {0, INT_MAX};

        while (!pq.empty())
        {
           auto [val, list_idx, ele_idx] = pq.top();
           pq.pop();

           // b - a < d -c 
           if (curMax - val < ans[1] - ans[0])
             ans = {val, curMax};

           if (ele_idx + 1 == nums[list_idx].size())
             break;
            
           int nxt = nums[list_idx][ele_idx+1];
           pq.push({nxt, list_idx, ele_idx+1});
           curMax = max(curMax, nxt);
        }

        return ans;
    }
};