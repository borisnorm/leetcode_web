class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0)
          return 0;
        
        //unordered_map<int, int>
        sort(nums.begin(), nums.end());

        int duplicate_num_xor = 0;
        for (int i = 1; i < n; i++ )
        {
           if (nums[i] == nums[i-1])
              duplicate_num_xor ^= nums[i];
        }

        return duplicate_num_xor;          
 
    }
};