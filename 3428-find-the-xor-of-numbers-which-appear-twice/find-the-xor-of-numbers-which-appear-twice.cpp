class Solution {
public:
int duplicateNumbersXOR(vector<int>& nums) {
      
      int n = nums.size();
      if (n == 0)
        return 0;
    
      int duplicate_num_xor = 0;
      unordered_set<int> num_set;
      for (int num: nums)
      {
        if (num_set.count(num))
          duplicate_num_xor ^= num;
        else
          num_set.insert(num);
      }
      
      return duplicate_num_xor;
    }
    /*
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
    */
};