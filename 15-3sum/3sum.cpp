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

        for (int i = 0; i < n - 2; i++)
        {
           int target = 0 - nums[i];

           int l = i + 1;
           int r = n - 1;

           if (i > 0 && nums[i] == nums[i-1])
             continue;
         
           while (l < r)
           {
             int sum = nums[l]+nums[r];
             if (sum < target)
              l++;
             else if (sum > target)
              r--;
             else
             {

                while (l < r && nums[l] == nums[l+1])
                  l++;

                while (r > l && nums[r] == nums[r-1])
                  r--;

                res.push_back({nums[i], nums[l], nums[r]});

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