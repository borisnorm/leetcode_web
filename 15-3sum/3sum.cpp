class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty())
          return {};

        vector<vector<int>> res;
        int n = nums.size();

        if (n < 3)
          return res;

        sort(nums.begin(), nums.end());
    
        //换成  nums[i] , nums[i+1], nums[i+2] 就更好理解
        //              i + 2 < n;
        for (int i = 0; i < n - 2; i++)
        {
           if (i > 0 && nums[i] == nums[i-1])
             continue;

           if (nums[i] > 0)
             break;
         
           if (nums[i] + nums[i+1] + nums[i+2] > 0)
             break;
           
           if (nums[i] + nums[n-2] + nums[n-1] < 0)
             continue;

           int target = 0 - nums[i];

           int l = i + 1;
           int r = n - 1;
         
           while (l < r)
           {
             long long sum = 1LL*nums[l]+nums[r];
             if (sum < target)
              l++;
             else if (sum > target)
              r--;
             else
             {
                res.push_back({nums[i], nums[l], nums[r]});
                //留下的是 最后一个 相同值的 l, 不是 l+1, 当 l 与 l+1不相同的时候, l 不会向前迈的
                //l+1是那个不同, 停在了最后一个与前面值相同的l上面
                while (l < r && nums[l] == nums[l+1])
                  l++;
                while (r > l && nums[r] == nums[r-1])
                  r--;
                l++;
                r--;
             }

           }
        }

        /*
        for (int i = 1; i < res.size(); i++)
        {
           vector<int> it1 = res[i-1];
           vector<int> it2 = res[i];

           if( (it1[0] == it2[0]) && (it1[1] == it2[1]) && (it1[2] == it2[2]))
           {
              res.erase(res.begin() + i);
              i = i - 1;
           }
        }
        */

        return res;
    }
};