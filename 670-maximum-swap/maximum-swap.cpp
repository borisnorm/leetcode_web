class Solution {
public:
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

            if (maxPos != i && num_str[maxPos] > num_str[i])
            {
              swap(num_str[i], num_str[maxPos]);
              return stoi(num_str);
            }
        }

        return num;
    }
};