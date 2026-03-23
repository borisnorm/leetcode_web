class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        //余数的 vector
        vector<int> remainCnt(k, 0);
        remainCnt[0] = 1;

        int prefix = 0;
        int subArrCnt = 0;
        for(int num: nums)
        {
           prefix += num;

           int remain = ((prefix % k) + k) % k;

           /* 之前的 remain prefix point  到  这个点 都能构成 sub array */
           subArrCnt += remainCnt[remain];

           remainCnt[remain]++;
        }

        return subArrCnt;
    }
};