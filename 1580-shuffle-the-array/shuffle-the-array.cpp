class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            // push_back 不能初始化 vector 的大小
            res.push_back(nums[i]);
            res.push_back(nums[i + n]);  // 2n-1 = n-1+n 
        }

        return res;
    }
};
/*
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2*n, 0);
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            res[idx]   = nums[i];
            res[idx+1] = nums[i + n];  // 2n-1 = n-1+n 
            idx += 2;
        }

        return res;
    }
};
*/