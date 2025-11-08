class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
       if (nums.empty())
         return {};

       vector<string> res;

       int left = 0;
       int cur = left;
        string num_str;
       for (int i = 1; i < nums.size(); i++)
       {
          if (nums[cur] + 1 == nums[i])
          {
            cur++;
          }
          else
          {
             if (left != cur)
             {
               num_str = to_string(nums[left]) + "->" + to_string(nums[cur]);
               res.push_back(num_str);
             }
             else
             {
               num_str = to_string(nums[left]);
               res.push_back(num_str);
             }

             left = i;
             cur = left;
          }
       }

       if (left != cur)
       {
         num_str = to_string(nums[left]) + "->" + to_string(nums[cur]);
         res.push_back(num_str);
       }
       else
       {
         num_str = to_string(nums[left]);
         res.push_back(num_str);
       }

       return res;
    }
};