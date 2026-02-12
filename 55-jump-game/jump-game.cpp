
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
            // 我们已经 滚动到 i 了, 可以 farthest 却还没追上, 直接 false 看就好了
            if (i > farthest)
              return false;

           // 不可以是 farthest, farthest可能在很远的地方, 只有 跳到 i 才可以 加上 nums[i]
           // 需要现在的 access 跳到 farthest 的时候才可以  farthest + nums[i]
           // 现在 显然不是, 现在是假设 在 [start, farthest] 范围内 跳到 i 上是否可以到达更远的地方
           // 所以 这里是 当前位置的 i + nums[i] 才会形成有效的语义
            farthest = max(farthest, i + nums[i]);

         }

         return (farthest >= n-1) ? true: false;
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
            // 被卡住
            if (farthest <= i)
              return false;
         }

         return true;
    }
};
*/