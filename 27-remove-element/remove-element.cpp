
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        
        int k = 0;
        int slow = 0;
        int fast = 0;
        // 快慢覆写 完全不需要考虑 是 n-1还是 n的循环个数问题,
        // 最后 slow 指向的位置就是就是需要被 设置为空的地方;
        /* 
        for (int i = 0; i < n-1; i++)
        {
            if (nums[i] != val)
            {
               nums[slow++] = nums[i];
            }
        }
        */
        for (fast = 0; fast < n; fast++)
        {
           if (nums[fast] != val)
           {

              nums[slow++] = nums[fast];
              k++;
           }
        }


        return k;
        
    }
};
/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        if (nums.empty())
          return 0;

        int slow = 0;
        while (slow < nums.size())
        {          
          if (nums[slow] == val)
          {
            for (int i = slow; i < nums.size() - 1; i++)
              nums[i] = nums[i+1];
            cnt++;
          }

          slow++;
        }

        for (int i = 0; i < cnt; i++)
        {
            vector<int>::iterator iter = nums.end();
            nums.erase(nums.end()-1);
        }

        return nums.size();
    }
};

*/