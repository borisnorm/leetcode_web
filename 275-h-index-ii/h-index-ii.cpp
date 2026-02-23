class Solution {
public:

 int hIndex(vector<int>& citations) {
     
     int n = citations.size();
     int l = 0;
     int r = n;

     //find first >= h (n-mid) 闭区间写法
     //二分搜索的是 citations 数组的下标，通过下标间接判断条件

     // 二分 边界搜素 也有 开区间 与 闭区间 2种写法, 
     // 只是对于 闭区间, 搜索左边界,答案 在 l, 搜索右边界, 答案在 r
     // 而      开区间, 答案都是 l
     while (l < r)
     {
        int mid = l + (r-l)/2;

        if (citations[mid] >= (n - mid))
          r = mid;
        else
          l = mid + 1;
     }

     return n-l;

   }
 };

/*
class Solution {
public:

    int hIndex(vector<int>& citations) {

        int n = citations.size();
        int h = 0;
        for (int i = 0; i < n; i++)
        {
            int papers = n - i;
            if (citations[i] >= papers)
              h = max(h, papers);
        }

        return h;
    }
};
*/
