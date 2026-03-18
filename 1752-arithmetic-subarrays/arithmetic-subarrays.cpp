class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();

        vector<bool> res(m, false);
        for (int i = 0; i < m; i++)
        { 
           res[i] = check(nums, l[i], r[i]);
        }

        return res;
    }

    bool check(vector<int>& nums, int l, int r)
    {
        int n = r-l+1;
        if (n == 1)  //只有1个元素也是 true
          return true;
        
        int min = *min_element(nums.begin()+l, nums.begin()+r+1);
        int max = *max_element(nums.begin()+l, nums.begin()+r+1);

        int maxDiff = max - min;
        if ((maxDiff % (n-1)) != 0)
          return false;
        
        int diff = maxDiff / (n-1);

        //公差为0,所有元素相等
        if (diff == 0)
          return true; // min==max 已经验证了其他元素

        // +1 是  [nums.begin(), nums.end())   [l, r)
        unordered_set<int> nums_set(nums.begin()+l, nums.begin()+r+1);

        for (int i = 0; i < n; i++)
        {
            int expected = min + diff * i;
            if (!nums_set.count(expected))
              return false;
        }

        return true;
    }

};