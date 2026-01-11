class Solution {
public:

  vector<int> findErrorNums(vector<int>& nums) {
       
       int n = nums.size();
       int dup = 0;
       int miss = 0;
       vector<int> res;
       for (int i = 0; i < n; i++)
       {
          int x = abs(nums[i]);
          if (nums[x-1] < 0)
            dup = x;
          else
            nums[x-1] = -nums[x-1];
       }

       for (int i = 0; i < n; i++)
       {
          if (nums[i] > 0)
          {
            miss = i + 1;
            break;
          }
       }
    
       res.push_back(dup);
       res.push_back(miss);

       return res;
  }
/*
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

    */
};