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
           
           // prefixSum[j] - prefixSum[i] = k
           // prefixSum[i] = prefix[j] - k;
           // check if previous prefixSum[i] does exist or not
           // 与 two Sum 那个题 类似
           // [i + 1, j] 就是这个解
           if (prefixSumCnt.count(prefixSum - k))
             cnt += prefixSumCnt[prefixSum - k];

           prefixSumCnt[prefixSum]++;
        }

        return cnt;
    }
};