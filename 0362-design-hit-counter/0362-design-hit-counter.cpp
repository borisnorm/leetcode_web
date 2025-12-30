class HitCounter {
private:
    vector<int> times;
    vector<int> hits;   
public:
    HitCounter(): times(300, 0), hits(300, 0) {
       
    }
    
    void hit(int timestamp) {
        int idx = timestamp % 300;
        if (times[idx] != timestamp)
        {
           times[idx] = timestamp;
           hits[idx] = 1;
        }
        else
          hits[idx]++;

    }
    
    int getHits(int timestamp) {
        int hits_cnt = 0;
        for (int i = 0; i < 300; i++)
        {
           if (timestamp - times[i] < 300)
           {
              hits_cnt += hits[i];
           }
        }

        return hits_cnt;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */