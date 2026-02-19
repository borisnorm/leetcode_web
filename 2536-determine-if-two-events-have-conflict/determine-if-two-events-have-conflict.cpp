class Solution {
public:
    
   bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if (event1[0] <= event2[1] && event2[0] <= event1[1])  
          return true;
        
        return false;
   }
};
/*
class Solution {
public:
    
    struct eventTimer{
        int hour;
        int min;
    };
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        
         eventTimer* e1_start = buildEvtTimer(event1[0]);
         eventTimer* e1_end   = buildEvtTimer(event1[1]);
         eventTimer* e2_start = buildEvtTimer(event2[0]);
         eventTimer* e2_end   = buildEvtTimer(event2[1]);

        //if (event1.start < event2.end && event2.start < event1.end)
        if (lessThan(e1_start, e2_end) && lessThan(e2_start, e1_end))
          return false;
        
        return true;
    }

    eventTimer* buildEvtTimer(const string& event_str)
    {
        eventTimer* evtTimer = new eventTimer();
        string part;
        if (getline(event_str, part, ':'))
        {
          evt.hour = stoi(part);
        }

        if (getline(event_str, part, ':'))
         evt.min = stoi(part);
        
        return evtTimer;
    }

    bool lessThan(eventTimer* e1, eventTimer* e2)
    {
        if (e1->hour < e2->hour)
          return true;
        else
          return e1.min < e2.min;
    }
};
*/