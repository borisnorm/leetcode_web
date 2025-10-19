class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || !k)
           return;

        int n = nums.size();
        if (n <= 1)
          return;

        k = k % n;
        if (!k)
          return;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());

        return;  
    }
};