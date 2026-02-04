
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())
          return;
        
        int n = nums.size();

        int slow = 0;
        for (int fast = 0; fast < n; fast++)
        {
            if (nums[fast] != 0)
            {
                if (slow != fast)
                  swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};

/*
// slow 覆写 然后 把 slow 后面的全部填充为0
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())
          return;
        
        int n = nums.size();

        int slow = 0;
        for (int fast = 0; fast < n; fast++)
        {
            if (nums[fast] != 0)
            {
                //if (slow != fast)
                //  swap(nums[slow], nums[fast]);
                nums[slow] = nums[fast];
                slow++;
            }
        }

        for(int i = slow; i < n; i++)
          nums[i] = 0;

    }
};
*/

/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        
        while (fast < n)
        {
          if (nums[fast] != 0)
          {
             swap(nums[slow], nums[fast]);
             slow++;
          }
        
          fast++;
        }
    }
};
*/