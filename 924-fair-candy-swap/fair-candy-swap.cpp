class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
          
          int aliceSum = 0;
          for (int aliceCnt : aliceSizes)
            aliceSum += aliceCnt;
          
          int bobSum = 0;
          for (int bobCnt : bobSizes)
            bobSum += bobCnt;
          

          // alice - x + y = Bob - y + x
          // alice - Bob = 2(x-y)
          // x - y = 

         for (int aliceCnt : aliceSizes)
         {
            for (int bobCnt : bobSizes)
            {
                if ((aliceCnt - bobCnt) * 2 == (aliceSum - bobSum))
                  return {aliceCnt, bobCnt};
            }
         }

         return {}; 
    }
};