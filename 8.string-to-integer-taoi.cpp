#include <string>
#include <string.h>
#include <limits.h>
#include <iostream>
class Solution {
public:
    int myAtoi(std::string str) {
        int result=0, margin = 0;
        bool is_minus = false, over= false, with_operation = false;
        const char *number;
        number = str.c_str();
        for(int i=0; i<strlen(number); i++){
            if(!with_operation && isspace(number[i])){
                continue;
            } else if (!with_operation && number[i] == '+') {
                with_operation = true;
            } else if (!with_operation && number[i] == '-'){
                is_minus = 1;
                with_operation = true;
            } else if (isalpha(number[i])) {
                break;
            } else if (isdigit(number[i])) {
                if (result == 214748364 && number[i]-48 > 7){
                    if(is_minus){
                        result = INT_MIN;
                    } else {
                        result = INT_MAX;
                    }
                    break;
                }
                result = result * 10 + (number[i]-48);
                if(result > 214748364 && i+1<strlen(number) && isdigit(number[i+1])){
                    if(is_minus){
                        result = INT_MIN;
                    } else {
                        result = INT_MAX;
                    }
                    break;
                }
                with_operation = true;

            } else {
                break;
            }
        }
        if(is_minus && result != INT_MIN){
            result = 0 - result;
        }

        return result;
        
        
    }
};

int main(){
    Solution s;
    std::cout << s.myAtoi("-2147483646") << std::endl;
}

