class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        if (nums.empty())
          return nums;
        
        int n = nums.size();
        int left = 0; 
        int right = n - 1;
        int pos = n - 1;

        vector<int> res(n);
        for (int i = 0; i < n; i++)
            nums[i] = nums[i]*nums[i];

        while (left <= right)
        {
           if (nums[left] <= nums[right])
           {
              res[pos] = nums[right];
              right--;
           }
           else
           {
              res[pos] = nums[left];
              left++;
           }
           pos--;
        }

        return res;
    }
};