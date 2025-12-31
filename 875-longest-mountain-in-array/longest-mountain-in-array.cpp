class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        if (n < 3)
          return 0;

        int i = 0;
        int maxLen = 0;
        //for (int i = 1; i < n; i++)
        while(i < n)
        {
           int start = i;
           int j = start + 1;

           while (j < n && arr[j-1] < arr[j])
             j++;
           int peak = j-1; 
           
             
           while (j < n && arr[j-1] > arr[j])
             j++;
           
           int end = j;
           int len = end - start;


           if (start < peak && peak + 1 < end)
             maxLen = max(maxLen, len);

           //if (start == end)
             i++;
         }

        return maxLen;
    }
};