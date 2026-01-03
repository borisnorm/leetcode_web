class Logger {
public:
    unordered_map<string, int> msg2tm;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
         if (!msg2tm.count(message))
         {
           msg2tm[message] = timestamp;
           return true;
         }

          if (timestamp - msg2tm[message] >= 10)
          {
            msg2tm[message] = timestamp;
            return true;
          }

          return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */