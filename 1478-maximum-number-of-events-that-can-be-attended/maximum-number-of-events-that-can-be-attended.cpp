class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        if (n == 0)
          return 0;

        sort(events.begin(), events.end());
        // 小顶堆  谁先结束, 谁弹出
        priority_queue<int, vector<int>, greater<int>> pq;

        int day = 0;
        int idx = 0;
        int res = 0;

       /* 
        while (还有事件没处理)
        {
          [今天] 入堆所有今天开始的事件
          [今天] 清除过期事件
          [今天] 参加一个事件
          day++  ← 今天结束，进入明天
        }
        */

        while (idx < n || !pq.empty())
        {
           // set next event start time
           if (pq.empty())
             day = events[idx][0];
          
           //将 idx 之后的 event, 然后 又 < day event 都入堆
           while (idx < n && events[idx][0] <= day)
           {
              pq.push(events[idx][1]);
              idx++;
           }

           //expired day
           while (!pq.empty() && day > pq.top())
             pq.pop();
           
           // 参加最早结束的 event
           if(!pq.empty())
           {
              pq.pop();  //这一天 用掉了
              res++;
           }

           day++;  //进入下一天
        }
        return res;
    }
};