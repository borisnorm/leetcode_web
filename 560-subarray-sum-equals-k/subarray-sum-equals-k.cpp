class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // subarray equals to K 

        unordered_map<int, int> prefixSumCnt;
        prefixSumCnt[0] = 1;
        int cnt = 0;
        int prefixSum = 0;

        for (int num: nums)
        {
           prefixSum += num;
           
           if (prefixSumCnt.count(prefixSum - k))
             cnt += prefixSumCnt[prefixSum - k];

           prefixSumCnt[prefixSum]++;
        }

        return cnt;
    }
};