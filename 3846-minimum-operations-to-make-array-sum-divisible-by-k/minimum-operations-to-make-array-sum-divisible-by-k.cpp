class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        

        int n = nums.size();
        int minOps = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
          sum += nums[i];

        minOps = sum % k;
        
        return minOps;
    }
};