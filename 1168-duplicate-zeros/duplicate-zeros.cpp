class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = (int)arr.size();
        int zeros = 0;
        for (int x : arr) if (x == 0) zeros++;

        // i 指向原数组末尾，j 指向“虚拟扩展数组”的末尾
        int i = n - 1;
        int j = n + zeros - 1;

        while (i >= 0) {
            if (arr[i] == 0) {
                if (j < n) arr[j] = 0;
                j--;
                if (j < n) arr[j] = 0;
                j--;
            } else {
                if (j < n) arr[j] = arr[i];
                j--;
            }
            i--;
        }
    }
};

/*
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        // Step 1: 统计可复制的 0
        for (int i = 0; i + zeros < n; i++) {
            if (arr[i] == 0) {
                // 边界：最后一个 0 只能放一个
                if (i + zeros == n - 1) {
                    arr[n - 1] = 0;
                    n--;   // 缩小有效长度
                    break;
                }
                zeros++;
            }
        }

        // Step 2: 从后往前写
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                arr[i + zeros] = 0;
                zeros--;
                arr[i + zeros] = 0;
            } else {
                arr[i + zeros] = arr[i];
            }
        }
    }
};
*/

/*
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zero_cnt = 0;

        for (int i = 0; i + zero_cnt < n; i++)
        {
            if (arr[i] == 0)
            {
               if (i + zero_cnt == n - 1)
               { 
                 arr[n-1] = 0;
                 n--;
                 break;
               }
                
               zero_cnt++;
            }
        }

        for (int i = n - 1; i >=0; i--)
        {
           if (arr[i] == 0)
           {
              arr[i + zero_cnt] = 0;
              zero_cnt--;

              arr[i + zero_cnt] = 0;
           }
           else
           {
              arr[i + zero_cnt] = arr[i];
           }
        }

    }
};
*/

/*
class Solution {
public:

    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zero_cnt = 0;

        for (int i = 0; i < n; i ++)
        {
           if (i + zero_cnt >= n)
             break;
           if (arr[i] == 0)
           {
              zero_cnt++;
           }
        }

        int lastIdx = n - 1 - zero_cnt;  // 变更后的 lastIdx
        if (lastIdx >= 0 && arr[lastIdx] == 0 && lastIdx + zero_cnt >= n)
        {
            arr[n-1] = 0;  // 实际的 lastIdx
            zero_cnt--;
            lastIdx--;
        }


        for (int i = lastIdx; i >= 0; i--)
        {
           if (arr[i] == 0)
           {
             arr[i + zero_cnt] = 0;
             zero_cnt--;
             arr[i + zero_cnt] = 0;
           }
           else
           {
              arr[i + zero_cnt] = arr[i];
           }
        }
        
    }
};

/*

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int n = arr.size();
        bool isDuplicated = false;
        for(int i = 0; i < n; i++)
        {
           if (isDuplicated)
           {
              isDuplicated = false;
              continue;
           }

           if (!isDuplicated && arr[i] == 0 )
           {
             for (int j = n - 1; j-1 >= i; j--)
             {
                 // 已经包括 复制 0了
                 arr[j] = arr[j-1];
             }

             isDuplicated = true;
           }
        }

        
    }
    
};
*/