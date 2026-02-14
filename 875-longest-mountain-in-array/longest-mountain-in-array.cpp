class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) 
           return 0;

        int maxLen = 0;
        int i = 0;

        while (i < n-1) {
            int start = i;

            // 1) 先走严格上升, 如果 相等 = 或是 大于 >, 这里 start 就 == i 了,  
            while (i + 1 < n && arr[i] < arr[i + 1]) 
              i++;
            int peak = i;

            // 2) 再走严格下降, 如果 相等 = 或是 小于 <, 这里 end 就 == i 了,
            while (i + 1 < n && arr[i] > arr[i + 1]) 
              i++;
            int end = i;

            // 3) 必须同时有上升和下降，且长度>=3, 也就是 同时检查 (1) 与 (2)
            // 判断 maxlen 是否合法 
            // 比如 1. 全相等的 len   start = end = 0       len = start - end + 1  = 1
            //     2. 一直升序的 len [1,2,3,4,5]            len = n - 1 - 0 + 1 = n    
            //     3. 一直降序的 len [5,4,3,2,1] end = n-1, len = end - start + 1 = n 
            if (start < peak && peak < end) 
            {
                maxLen = max(maxLen, end - start + 1);
            }

            // 4) 关键：如果没动（平台或无法形成上升），前进一格避免死循环
            // arr = [1, 1, 1, 3, 2]
            // arr = [1, 2, 2, 3, 1]
            // 索引   0  1  2  3  4
            if (end == start) 
              i++;
        }

        return maxLen;
    }
};
