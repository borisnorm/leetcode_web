class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};

        for (char task: tasks)
          freq[task-'A']++;
        
        int maxFreq = 0;
        int maxFreqCnt = 0;

        for (int i = 0; i < 26; i++)
        {
           if (freq[i] > maxFreq)
           {
              maxFreq = freq[i];
              maxFreqCnt = 1;
           }
           else if (freq[i] == maxFreq)
           {
              maxFreqCnt++;
           }
        }
        // 'a, a, a' maxFreq-1,  2(3-1) intervals required
        //  n= 2, intervalsLen = n + 1,   a-idle-idle, +1 includes a itself
        //  a idle idle a idle idle a(tail) = maxFreqCnt
        int nInterval = maxFreq - 1;
        int intervalLen = n + 1;
        int intervalTail = maxFreqCnt;
        int nTaskInterval = nInterval * intervalLen + intervalTail;
       
        // maxFreqCnt > n, 排列处理好了
        // a b c d a b c d a b c d

        int minTasksInterval = std::max(nTaskInterval, (int)tasks.size());
         
        return minTasksInterval;
    }

/*
    int leastInterval(vector<char>& tasks, int n) {
         vector<int> freq(26, 0);
         for (char task: tasks)
           freq[task-'A']++;

         int maxFreq = 0;
         int countOfMax = 0;

         for (int count: freq)
         {
           if (count > maxFreq)
           {
              maxFreq = count;
              countOfMax = 1;
           }
           else if (count == maxFreq)
           {
             countOfMax++;
           }
         }

           int result = (maxFreq - 1) * (n+1) + countOfMax;
           return max(result, (int)tasks.size());
    }
    */
};