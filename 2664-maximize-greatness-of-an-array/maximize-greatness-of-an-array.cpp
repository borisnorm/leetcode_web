class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        sort (nums.begin(), nums.end());
        int cnt = 0;

        while (i < n && j < n)
        {
           if (nums[j] > nums[i])
           {
              cnt++;
              i++;
              j++;
           }
           else
           {
              j++;
           }
        }
        return cnt;
    }
};