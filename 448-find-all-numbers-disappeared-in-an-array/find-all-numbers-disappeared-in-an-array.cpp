class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         vector<int> res;
         int n = nums.size();
         if (n == 0)
           return res;

         unordered_set<int> nums_set;
         for (int num: nums)
           nums_set.insert(num);
        
         for (int i = 1; i <= n; i++)
         {
            if (!nums_set.count(i))
              res.push_back(i);
         }

         return res;
    }
};