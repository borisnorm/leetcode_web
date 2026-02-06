class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty())
          return;
        
        int n = nums.size();

        // go through from end to front, find first i < i+1, i as prefix, i+1 to end as suffix, suffix is decreasing in order
           // reverse the exising max permutation if not found
        int i = n-2;
        while (i >= 0 && nums[i] >= nums[i+1])
          i--;
        if (i < 0)
        {
           reverse(nums.begin(), nums.end());
           return;
        }
    
        // go throught from end to front, find first j > i
        // then swap them, to gurantee the min prefix and max suffix
        // as suffix is been in decrasing order, which is the max number in ascending order
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i])
          j--;
        swap(nums[i], nums[j]);
        
        //reverse the suffix to the end 
        reverse(nums.begin()+i+1, nums.end());
    }
};

/*
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty())
          return;

        int n = nums.size();
        // 1. find the fisrt nums[p] < nums[p+1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i+1])
          i--;
        if (i < 0)
        {
            // 已是最大排列 -> 变最小
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2. find the fist nums[j] > nums[i]
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i])
          j--;
        
        // 3. swap p and q
        swap(nums[i], nums[j]);

        // 4. reverse after p postion suffix
        // suffix 后面已经是可能的最大值了
        reverse(nums.begin()+i+1, nums.end());
    }
};

*/