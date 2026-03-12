class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin(), meetings.end());
      
        // min-head roomId
        priority_queue<int, vector<int>, greater<int>> free;
        // min-heap   //end time, roomId
        using T = pair<long long, int>;
        priority_queue<T, vector<T>, greater<>> busy;

        vector<int> roomCnt(n, 0);

        //init free room
        for (int i = 0; i < n; i++)
          free.push(i);


        // busy -> free
        // free -> busy
        // busy -> busy
        int roomId = 0;
        for (int i = 0; i < m; i++)
        {
          long long startT = meetings[i][0];
          long long endT   = meetings[i][1];
          long long dur    = endT - startT;
          // free busy room
          while(!busy.empty() && meetings[i][0] >= busy.top().first)
          {
             roomId = busy.top().second;
             busy.pop();
             free.push(roomId);
          }

    
          // for 循环中 表示 有 meeting 要进行了
          if (!free.empty())
          {
             roomId = free.top();
             free.pop();
             busy.push({endT, roomId});
          }
          else
          {
             auto [lastEndT, lastRoomId] = busy.top();
             busy.pop();
             roomId = lastRoomId;
             // 在没有可用 room 的 case 下
             // delay当前会议, 所以是 lastEndT + dur 而不是使用 endT
             busy.push({lastEndT + dur, roomId});
          }

          roomCnt[roomId]++;
        }
        
        int maxCnt = 0;
        int maxCntIdx = 0;
        for (int i = 0; i < n; i++)
        {
           if (roomCnt[i] > maxCnt)
           {
              maxCnt = roomCnt[i];
              maxCntIdx = i;
           }
        }

        return maxCntIdx;
    }
};