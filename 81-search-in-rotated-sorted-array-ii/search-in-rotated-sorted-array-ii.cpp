class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;

        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return true;

            // 关键：处理重复元素的情况
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                // 无法判断哪一边有序，只能缩小范围
                l++;
                r--;
            }
            // 左半边有序
            else if (nums[l] <= nums[mid]) {
                // target 在左半边
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // 右半边有序
            else {
                // target 在右半边
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return false;
    }
};