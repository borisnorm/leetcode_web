class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return -1;

        int left = 0;
        int right = (int)nums.size() - 1;
        int ans = nums[0];                       // 候选最小值

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= nums[right])
            {      // mid 落在右段（含最小值）
                ans = min(ans, nums[mid]);                 // 更新答案
                right = mid - 1;                 // ---> 注意：收缩右边，但保留更小可能
            } else 
            {                             
               left = mid + 1;                  // mid 在左段，最小值在右边
            }
        }
        return ans;
    }
};
