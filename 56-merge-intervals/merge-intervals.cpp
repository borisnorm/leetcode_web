class Solution {
public:

    // 时间复杂度是  O(nlog(n))   排序 是 nlog(n) + merge O(n)
    // 空间复杂度    O(1)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
          return {};

          int n = (int) intervals.size();
          if (n <= 1)
            return intervals;

          //排序以后，所有区间都是“向左合并”的，不存在“向右合并”。
          //Merge Intervals = 排序确定 start，扫描过程中只扩展 end
          // 左端 通过 start 端的合并是通过 sort 排序来完成的
          // 右端 通过 更新 end 段来完成合并
          sort(intervals.begin(), intervals.end());

          vector<vector<int>> res;

          res.push_back(intervals[0]);

          for (int i = 1; i < n; i++)
          {
             auto& lastInterval = res.back();
             if (intervals[i][0] <= lastInterval[1])
               //更新 LastInterval 的 endTime, 
               //LastInterval 已经在 res 里面了, 这只是在更新 last
               //
               lastInterval[1] = max(lastInterval[1], intervals[i][1]);
             else
               res.push_back(intervals[i]);
          }

          return res;
    }
};


/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int m = intervals.size();
        if (m <= 0)
            return {};
        int n = intervals[0].size();
        if (n <= 0)
            return {};

        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);

        int start = 0;
        int end = 0;
        for (int i = 1; i < m; i++) {
            vector<int>& last = res.back();
            // auto& last = res.back();  //正确
            // vector<int> last = res.back(); //错误 无法修改 last
            if (intervals[i][0] <= last[1]) {

                last[1] = max(last[1], intervals[i][1]);
                //start = min(res[i - 1][0], intervals[i][0]);
                //end = max(res[i-1][1], intervals[i][1]);
                //res[i - 1][0] = start;
                //res[i - 1][1] = end;
            } 
            else
              res.push_back(intervals[i]);
        }

        return res;
    }
};

*/