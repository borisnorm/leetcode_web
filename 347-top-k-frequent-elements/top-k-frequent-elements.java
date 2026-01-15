class Solution {
  public int[] topKFrequent(int[] nums, int k) {
       int n = nums.length;

       HashMap<Integer, Integer> num2freq = new HashMap<>();
       for (int num: nums)
         num2freq.put(num, num2freq.getOrDefault(num, 0)+1);
        
       List<Integer>[] bucket = new List[n+1];

       for (int num : num2freq.keySet())
       {
          int freq = num2freq.get(num);

          if (bucket[freq] == null)
            bucket[freq] = new ArrayList<>();

          bucket[freq].add(num); 
       }
      /* 正确
       for (Map.Entry<Integer, Integer> e: num2freq.entrySet())
       {
           int val = e.getKey();
           int freq = e.getValue();

           if (bucket[freq] == null)
             bucket[freq] = new ArrayList();

           bucket[freq].add(val);
       }
       */

       int[] res = new int[k];

       int cnt = 0;
       int idx = 0;
       for (int i = n; i >= 1 && cnt < k; i--)
       {
          List<Integer> vals = bucket[i];

          if (vals == null)
            continue;
            
          for (int val: vals)
          {
            res[idx++] = val;
            cnt++;
            if (cnt == k)
              break;
          } 
       }

       return res;
  }
    /*
    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;

        HashMap<Integer, Integer> num2freq = new HashMap<>();

        for (int num: nums)
        {
           num2freq.put(num, num2freq.getOrDefault(num, 0) + 1);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[1], b[1]));

        for (Map.Entry<Integer, Integer> e: num2freq.entrySet())
        {
           int val = e.getKey();
           int freq = e.getValue();
           pq.offer(new int[]{val, freq});

           if (pq.size() > k)
             pq.poll();
        }

        int[] res = new int[k];
        for (int i = k-1 ; i >=0; i--)
        {
           int[] vec = pq.poll();
           res[i] = vec[0];
        }

        return res;
        
    }

    */
}