class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty())
          return -1;

        // phase 1: 找相遇点  
        //int slow = nums[0];
        //int fast = nums[nums[0]];
        
        int slow = 0;
        int fast = 0;

        int n = nums.size();
        //数组长度为 n+1: 有效下标是 0 到 n，所以 nums[n] 完全合法，不越界。
        //数值范围: [1, n], 所以 nums[nums[fast]] 是有效的
        while (fast != n)
        {
          slow = nums[slow];
          fast = nums[nums[fast]];
          if (slow == fast)
            break;
        }

        // phase 2: 找环的入口（即重复数字）
        slow = 0;
        // fast 留在相遇点
        while (slow != fast)
        {
           slow = nums[slow];
           fast = nums[fast];
        }
        
        return slow; // 相遇点即为重复数字
    }
};

/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();

        int l = 1;
        int r = nums.size() - 1;

        int ans = -1;
      

        while (l <= r) 
        {
          int mid = (l + r) / 2;
          int cnt = 0;
          // 统计 <= mid 的 cnt 
          for (int num : nums) 
          {
            if (num <= mid)
              cnt++;
          }

          if (cnt > mid) 
          {
             ans = mid;
             r = mid - 1;
          } 
          else 
          {
            l = mid + 1;
          }
        }

        return ans;
    }
};

*/