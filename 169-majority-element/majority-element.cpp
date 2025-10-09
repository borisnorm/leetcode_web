class Solution {
public:
    int majorityElement(vector<int>& nums) {
       if (nums.empty())
         return -1;
        
        unordered_map<int, int> nums_map;
      
        int m = nums.size();
        for (int i = 0; i < m; i++)
          nums_map[nums[i]]++;

        int majority_cnt = INT_MIN;
        int majority_num = -1;
        for (auto iter: nums_map)
        {
            if (iter.second > m/2)
            {
              if (iter.second > majority_cnt)
              {
                 majority_cnt = iter.second;
                 majority_num = iter.first;
               }
            }
        }

        return majority_num;
    }
};