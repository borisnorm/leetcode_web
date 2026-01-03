class Logger {
public:
    unordered_map<string, int> msg2nextSlot;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
         if (!msg2nextSlot.count(message))
         {
           msg2nextSlot[message] = timestamp + 10;
           return true;
         }
         else
         {
            if (timestamp < msg2nextSlot[message])
              return false;
            else
            {
               msg2nextSlot[message] = timestamp + 10;
               return true;
            }
         }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */