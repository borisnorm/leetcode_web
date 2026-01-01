class Solution {
public:

    int maximumSwap(int num) {
        
        string num_str = to_string(num);
        int n = num_str.size();

        vector<int> lastPos(10, -1);  // 0-9

        for (int i = 0; i < n; i++)
        {
          char c = num_str[i];
          lastPos[c-'0'] = i;
        }

        for (int i = 0; i < n; i++)
        {
           int digit = num_str[i] - '0';

           for (int d = 9; d > digit; d--)
           {
              if (lastPos[d] > i)
              {
                 swap(num_str[i], num_str[lastPos[d]]);
                 return stoi(num_str);
              }
           } 
        }
        
        return num;

    }
/*
    int maximumSwap(int num) {
        
        string num_str = to_string(num);
        int n = num_str.size();

        for (int i = 0; i < n - 1; i++)
        {
            int maxPos = i;
            for (int j = i + 1; j < n; j++)
            {
                if (num_str[j] >= num_str[maxPos])
                { 
                   maxPos = j;
                } 
            }

            // 遇到 相等的情况下, 没有 num_str[maxPos] > num_str[i], 他就错误地直接返回了
            if (maxPos != i && num_str[maxPos] > num_str[i])
            {
              swap(num_str[i], num_str[maxPos]);
              return stoi(num_str);
            }
        }

        return num;
    }

    */
};