class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int maxLen = 0;
        int i = 0;

        while (i < n) {
            int start = i;

            // 1) 先走严格上升
            while (i + 1 < n && arr[i] < arr[i + 1]) i++;
            int peak = i;

            // 2) 再走严格下降
            while (i + 1 < n && arr[i] > arr[i + 1]) i++;
            int end = i;

            // 3) 必须同时有上升和下降，且长度>=3
            if (start < peak && peak < end) {
                maxLen = max(maxLen, end - start + 1);
            }

            // 4) 关键：如果没动（平台或无法形成上升），前进一格避免死循环
            if (end == start) i++;
        }

        return maxLen;
    }
};
