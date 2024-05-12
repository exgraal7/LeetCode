class Solution {
public:
    int myAtoi(std::string s) {
        size_t start = s.find_first_not_of(" \t\n\r");
        if (start == std::string::npos) return 0; 
      
        s = s.substr(start);  
      
        bool isPositive = true;  
        int i = 0;              
        int answer = 0;         
        if (s[i] == '+') {
            isPositive = true;  
            ++i;
        } else if (s[i] == '-') {
            isPositive = false; 
            ++i;
        }
      
        for (; i < s.length(); ++i) {
            
            int currentValue = s[i] - '0';
          
            if (currentValue < 0 || currentValue > 9) break;
            if (answer > INT_MAX / 10 ||
                (answer == INT_MAX / 10 && currentValue > INT_MAX % 10)) {
                return isPositive ? INT_MAX : INT_MIN;
            }
          
            answer = answer * 10 + currentValue;
        }
      
        return isPositive ? answer : -answer;
    }
};
