class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i + 1 < n; i++)
        {
           for (int j = i + 1; j < n; j++)
           {
              if (nums[i] == nums[j])
                cnt++;
           }
        }

        return cnt;
    }
};