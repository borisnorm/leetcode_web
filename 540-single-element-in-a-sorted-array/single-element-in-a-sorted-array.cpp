class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        int l = 0;
        int r = n -1; // 边界中有确定的值

        while(l < r)
        {
            int mid = l + (r-l)/2;

            if (mid & 0x1)
              mid--;
            
            if(nums[mid] == nums[mid+1])
              l = mid + 2;
            else
              r = mid;
        }

        return nums[l];

        
    }
};