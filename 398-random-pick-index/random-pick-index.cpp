class Solution {
public:
    vector<int> curNums;
    Solution(vector<int>& nums) {
        curNums = nums;
    }
    
    int pick(int target) {
        int n = curNums.size();

        int cnt = 0;
        int res = -1;
        for (int i = 0; i < n; i++)
        {
          if (curNums[i] == target)
          {
              cnt++;
          
              // cnt 在变 概率也在变
              // 选中被替换的 概率为 1/1, 1/2, 1/3, ...1/k
              if (rand() % cnt == 0)
              {
                  res = i;
              }
          }
        }

        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */