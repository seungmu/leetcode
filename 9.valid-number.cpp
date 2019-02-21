#include <string>
#include <string.h>
#include <iostream>
class Solution {
public:
    bool isNumber(std::string s) {
        const char * number = s.c_str();
        float result=0;
        bool is_number=false;
        bool is_dot=false;
        int i=0;
        bool h=false, e=false;
        for(; isspace(number[i]) && i<strlen(number); i++);
        if(i<strlen(number) && (number[i]== '+' || number[i] == '-')) i++;
        for(; isdigit(number[i]) && i<strlen(number); i++){
            is_number = true;
            h= true;
        }
        if(!is_dot && i<strlen(number) && number[i] == '.') {
            is_dot=true;
            i++;
        }
        for(; isdigit(number[i]) && i<strlen(number); i++){
            is_number = true;
            h= true;
        }
        if(!is_dot && i<strlen(number) && number[i] == '.') {
            is_dot=true;
            i++;
        }
        if(i<strlen(number) && number[i] == 'e') {
            e= true;
            is_number = false;
            i++;
        }
        if(e && i<strlen(number) && (number[i]== '+' || number[i] == '-')) i++;
        for(; isdigit(number[i]) && i<strlen(number); i++){
            is_number = e? h&&e: true;
        }
        for(; isspace(number[i]) && i<strlen(number); i++);
        return is_number && i == strlen(number);
    }
};

int main(){
    Solution s;
    s.isNumber("..");
}
