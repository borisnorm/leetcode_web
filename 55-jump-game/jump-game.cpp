
class Solution {
public:
    bool canJump(vector<int>& nums) {
         if (nums.empty())
           return false;

         int farthest = 0;
         int n = nums.size();
         for (int i = 0; i < n; i++)
         {
            // 不可达
            // i 是当前值, farthest 是上一次的计算预估值
            if (i > farthest)
              return false;
            farthest = max(farthest, i + nums[i]);

         }

         return true;
    }
};
/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
         if (nums.empty())
           return false;

         int farthest = 0;
         int n = nums.size();
         for (int i = 0; i < n-1; i++)
         {
            farthest = max(farthest, i + nums[i]);
            //fastest是 取值范围
            if (farthest <= i)
              return false;
         }

         return true;
    }
};
*/