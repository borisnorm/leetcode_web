class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // num[i] = num[i-1] + num[i+1]

        long long reach = 0;
        int patch = 0;
        int i = 0;
        while (reach < n)
        {
            if (i < nums.size() && nums[i] <= reach + 1)
            {
               reach += nums[i];
               i++;
            }
            else
            {
               reach += reach + 1;
               patch++;
            }
        }

        return patch;
    }
};