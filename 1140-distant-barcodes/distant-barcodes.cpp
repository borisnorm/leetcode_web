class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> barcode2freq;
        for (int x: barcodes)
          barcode2freq[x]++;
        
        using T = pair<int, int>;
        priority_queue<T> pq;
        for(auto& [barcode, freq]: barcode2freq)
           pq.push({freq, barcode});
        
        vector<int> res;
        while (!pq.empty())
        {
           auto [freq, barcode] = pq.top();
           pq.pop();

           if (!res.empty() && res.back() == barcode)
           {
               if (pq.empty())
                 break;

               auto [freq2, barcode2] = pq.top();
               pq.pop();

               res.push_back(barcode2);
               if (freq2-1 > 0)
                 pq.push({freq2-1, barcode2});

               pq.push({freq, barcode});
           }
           else
           {
              res.push_back(barcode);
              if (freq-1 > 0)
                pq.push({freq-1, barcode});
           }
        }

        return res;

    }
};