class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;
        sort(nums.begin(), nums.end());
        int sum = nums[0];
        int dup = 0;
        for (int i = 1; i < n; i++)
        {
           if (nums[i-1] != nums[i])
             sum += nums[i];
           else
             dup = nums[i-1];
        }

        int total = n * (n+1)/2;
        int missing = total - sum;

        res.push_back(dup);
        res.push_back(missing);
        
        return res;
    }
};