class RLEIterator {
public:
    
    vector<int> enc;
    int i = 0;
    RLEIterator(vector<int>& encoding) {
        enc = encoding;
        i = 0;
    }
    
    int next(int n) {
        
        // enc[i] 里面存的是单段的个数, 
        // 必须将 总长度 n 转换为单段的长度才可以
        while(i < enc.size())
        {

           if (n <= enc[i])
           {
             enc[i] -= n;
             return enc[i+1];
           }
           
           n -= enc[i];
           i += 2;
        }

        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */