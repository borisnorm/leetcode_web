class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int, int> num2cnt;
        for (int num: nums)
          num2cnt[num]++;
        
        int res = 0;

        for (auto& it: num2cnt)
        {
           if (k == 0)
           {
              if (it.second >=2)
                res++;
           }
           else
           {
              if (num2cnt.count(it.first + k))
                res++;
           }
        }

        return res;
    }
};