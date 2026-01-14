class TimeMap {

    static class TimeStampVal{
        String val;
        int timestamp;
        TimeStampVal(String val, int timestamp){
            this.val = val;
            this.timestamp = timestamp;
        }
    }

    HashMap<String, List<TimeStampVal>> kv;
    public TimeMap() {
        kv = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {

          TimeStampVal val = new TimeStampVal(value, timestamp);
          
          kv.computeIfAbsent(key, k->new ArrayList<>());
          // 等价于 
          //  if (!kv.containsKey(key))
          //    {
          //        kv.put(key, new ArrayList<>());
          //    }
          //

          kv.get(key).add(val);
    }
    
    public String get(String key, int timestamp) {

          if (!kv.containsKey(key))
            return "";

          List<TimeStampVal> val_vec = kv.get(key);
          int n = val_vec.size();

          int l = 0;
          int r = n;

          while (l < r)
          {
             int mid = l + (r - l)/2;

             if (val_vec.get(mid).timestamp <= timestamp)
               l = mid + 1;
             else 
               r = mid;
          }

          if (l - 1 < 0)
            return "";
          
          return val_vec.get(l-1).val;
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */