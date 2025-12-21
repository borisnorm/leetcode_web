class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size();

        int cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >=2 ; i--)
        {
            int j = 0; 
            int k = i - 1;

            while (j < k)
            {
                if (nums[j] + nums[k] > nums[i])
                {
                  // cnt 要 先计算 否则 k 就要被--了,然后计算 错误
                  // k-j 是 len, 但是不包括 第 k 下标
                  cnt += (k-j);
                  k--;
           
                }
                else
                  j++;
            }
        }

        return cnt;
    }
};