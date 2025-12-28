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
                 arr[j] = arr[j-1];
             }

             isDuplicated = true;
           }
        }
    }
};