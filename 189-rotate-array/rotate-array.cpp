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
 
        //[1, 2, 3, 4, 5, 6, 7]

        //[7, 6, 5, 4, 3, 2, 1]
        reverse(nums.begin(), nums.end());

        // start_idx + k = end_idx
        // [start_idx, end_idx)
        // end_idx - start_idx = k
        // reverse的语义
        // [5, 6, 7, 4, 3, 2, 1]
        reverse(nums.begin(), nums.begin()+k);

        // [5, 6, 7, 1, 2, 3, 4]
        reverse(nums.begin()+k, nums.end());

         //[5, 6, 7, 1, 2, 3, 4]

        return;  
    }
};