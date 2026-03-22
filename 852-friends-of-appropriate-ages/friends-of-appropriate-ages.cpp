class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> ageCnt(121, 0);

        for (int a: ages)
          ageCnt[a]++;
        
        vector<int> prefixSum(121, 0);
        prefixSum[0] = ageCnt[0];
        //[low, high]
        //pre[i] = 年龄 <= i 的总人数
        for (int i = 1; i <= 120; i++)
          prefixSum[i] = prefixSum[i-1] + ageCnt[i];
        
        int res = 0;
        for (int a = 1; a <= 120; a++)
        {
            if (ageCnt[a] == 0)
              continue;
            
            int low = (int)(0.5*a + 7);
            int high = a;

            if (low >= high)
              continue;
            //年龄在 (low, high] 的认识 = pre[hi] - pre[low]
            int validB = prefixSum[high] - prefixSum[low];

            // A 有 ageCnt[a]人, 每人可发 validB 个请求
            // 但 A 不能给自己发, 减去 ageCnt[a] 自身
            res += validB * ageCnt[a] - ageCnt[a];
        }

        return res;
    }
};