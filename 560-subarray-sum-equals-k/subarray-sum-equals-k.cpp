class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // subarray equals to K 

        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        int count = 0;
        int prefixSum = 0;

        for (int num: nums)
        {
           prefixSum += num;
           if (prefixSumCount.count(prefixSum - k))
             count += prefixSumCount[prefixSum - k];

           prefixSumCount[prefixSum]++;
        }

        return count;
    }
};