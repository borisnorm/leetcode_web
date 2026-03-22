class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();

        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++)
          jobs.push_back({difficulty[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int m = jobs.size();
        int j = 0;
        int best = 0;

        for (int i = 0; i < worker.size(); i++)
        {
           while (j < m && jobs[j].first <= worker[i])
           {
              //best里面包括了当前这个 job 能拿到的最大值值, 所以 worker 不用在向前搜索了是吧 ?
              //best 变量承担了这个职责，不是 jobs 本身
              //`best` 就是一个**滚动的前缀最大值**，每次 `j` 往右走，就把新工作的利润纳入比较。
              best = max(best, jobs[j].second);
              j++;
           }

           maxProfit += best;
        }
        return maxProfit;
    }
};