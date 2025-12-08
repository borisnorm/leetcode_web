class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> val2freq = new HashMap();
        for (int val: arr)
          val2freq.put(val, val2freq.getOrDefault(val, 0) + 1);
    
        Set<Integer> freq_set = new HashSet();
        for (int freq: val2freq.values())
        {
            if (!freq_set.add(freq))
              return false;
        }

        return true;
    }
}