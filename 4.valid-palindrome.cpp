#include <string>
#include <string.h>
class Solution {
public:
    bool isPalindrome(std::string s) {
        const char *str = s.c_str();
        int h, t;
        for(int h=0, t=strlen(str); h<t; h++, t--){
            while(!isalnum(str[h]) && h<t) h++; 
            while(!isalnum(str[t]) && h<t) t--; 
            if(h!=t && tolower(str[h]) != tolower(str[t])){
                return false;
            }
        }
        return true;
    }
};
