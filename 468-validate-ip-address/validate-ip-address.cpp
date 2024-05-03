class Solution {
public:
    bool isValidV4(string ip){
        if(count(ip.begin(), ip.end(),'.') != 3){
            return false;
        }

        vector<string> parts = split(ip, '.');
        if(parts.size() != 4){
            return false;
        }

        for(string part : parts){
            if(part.size() == 0 || part.size() > 3 || (part.size() > 1 && part[0] == '0')){
                return false;
            }

            for(char c : part){
                if(!isdigit(c)){
                    return false;
                }
            }

            if(stoi(part) < 0 || stoi(part) > 255){
                return false;
            }
        }
        return true;
    }
    bool isValidV6(string ip){
        if(count(ip.begin(), ip.end(),':') != 7){
            return false;
        }

        vector<string> parts = split(ip, ':');
        if(parts.size() != 8){
            return false;
        }

        for(string part : parts){
            if(part.size() == 0 || part.size() > 4){
                return false;
            }

            for(char c : part){
                if(!isdigit(c) && (!(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F'))){
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> split(string ip, char delimeter){
        vector<string> parts;
        string part;
        stringstream ss(ip);
        while(getline(ss, part, delimeter)){
            parts.push_back(part);
        }
        return parts;
    }
    string validIPAddress(string queryIP) {
        if(isValidV4(queryIP)){
            return "IPv4";
        }
        if(isValidV6(queryIP)){
            return "IPv6";
        }
        return "Neither";
    }
};