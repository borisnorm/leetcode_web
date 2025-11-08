class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
       if (nums.empty())
         return {};

       vector<string> res;

       int left = 0;
       int right = left;
        string num_str;
       for (int i = 1; i < nums.size(); i++)
       {
          if (nums[right] + 1 == nums[i])
          {
            right++;
          }
          else
          {
             if (left != right)
             {
               num_str = to_string(nums[left]) + "->" + to_string(nums[right]);
               res.push_back(num_str);
             }
             else
             {
               num_str = to_string(nums[left]);
               res.push_back(num_str);
             }

             left = i;
             right = left;
          }
       }

       if (left != right)
       {
         num_str = to_string(nums[left]) + "->" + to_string(nums[right]);
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