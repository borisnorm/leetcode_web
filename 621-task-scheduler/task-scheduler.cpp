class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         vector<int> freq(26, 0);
         for (char task: tasks)
         {
           freq[task-'A']++;
         }

         int maxFreq = 0;
         int countOfMax = 0;

         for (int count: freq)
           if (count > maxFreq)
           {
              maxFreq = count;
              countOfMax = 1;
           }
           else if (count == maxFreq)
           {
             countOfMax++;
           }

           int result = (maxFreq - 1) * (n+1)+countOfMax;
           return max(result, (int)tasks.size());
    }
};