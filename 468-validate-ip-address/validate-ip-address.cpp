class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos)
           return isIPv4Valid(queryIP) ? "IPv4" : "Neither"; 
        else if (queryIP.find(':') != string::npos)
           return isIPv6Valid(queryIP) ? "IPv6" : "Neither";
        else
           return "Neither";
    }

    bool isIPv4Valid(const string& s)
    {
       vector<string> parts;
       string part;
       stringstream ss(s);
        
       if (s.empty() || s.front() == '.' || s.back() == '.')
          return false;
   
       while (getline(ss, part, '.'))
         parts.push_back(part);

       if (parts.size() != 4)
         return false;

       for (auto& p : parts)
       {
          if (p.empty() || p.size() > 3)
            return false;
        
          if (p.size() > 1 && p[0] == '0')
            return false;

          for (char c : p)
            if (!isdigit(c))
              return false;

          int val = stoi(p);
          if (val < 0 || val > 255)
            return false; 
       }

       return true;
    }

    bool isIPv6Valid(const string& s)
    {
        vector<string> parts;
        string part;
        stringstream ss(s);

        if (s.empty() || s.front() == ':' || s.back() == ':')
          return false;

        while (getline(ss, part, ':'))
          parts.push_back(part);

        if (parts.size() != 8)
          return false;
       
        for (auto & p : parts)
        {
           if (p.empty() || p.size() > 4)
             return false;

           for(auto c : p)
             if (!isxdigit((unsigned char)c))
               return false;
        }

        return true;
    }
};