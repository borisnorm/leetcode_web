class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
           if (nums.empty())
             return {};
            
            vector<int> res;
            unordered_map<int, int> nums_map;
            for (int i = 0; i < nums.size(); i++)
            {
               if (nums_map.count(target-nums[i]))
               {
                  auto iter = nums_map.find(target-nums[i]);
                  res.push_back(iter->second);
                  res.push_back(i);
                  return res;
               }

               nums_map[nums[i]] = i;
            }

            return res;
    }
};