class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
          return 0;

        unordered_set<int> nums_set(nums.begin(), nums.end());

        int ans = 0;
        int cur_len = 0;
        int cur_num = 0;
        for (int num : nums_set)   // for (int num: nums_set)
        {
           // 检查前一个数 确定当前数是不是起点
           if (nums_set.count(num-1))
              continue;
        
           // this num is the start point
           // 初始化起点 数据
           cur_len = 1;
           cur_num = num;

           // 检查下一个连续的数是否在 num_set 里面
           while (nums_set.count(cur_num+1))
           {
              cur_len++;
              // 更新 cur_num
              cur_num = cur_num + 1;
           }
           
           ans = max (ans, cur_len);
        }

        return ans;
    }
};
