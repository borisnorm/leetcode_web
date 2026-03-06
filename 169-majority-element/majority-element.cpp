class Solution {
public:
    int majorityElement(vector<int>& nums) {
       if (nums.empty())
         return -1;
      
       int m = nums.size();
       sort(nums.begin(), nums.end());
       
       return nums[m/2];
    }
};

/*
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
             //  下面的判断不是必须的 > m/2 只能是位置的 因为 m/2 + m/2 = m.
             // 如果存在2个元素都 > m/2 那最后的元素总数必然是 > m 的,但这时不可能的
             // if (iter.second > majority_cnt)
              {
                 majority_cnt = iter.second;
                 majority_num = iter.first;
               }
            }
        }

        return majority_num;
    }
};

*/