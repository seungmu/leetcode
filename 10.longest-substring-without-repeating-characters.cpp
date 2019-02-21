#include <string>
#include <string.h>
#include <map>
#include <iostream>
class Solution {    
public:
    int lengthOfLongestSubstring(std::string s) {
        int head=0, result=0, count = 0, old_head;
        const char *str = s.c_str();
        std::map<char, int> char_to_index;
        std::map<char, int>::iterator cti_it;
        for(int i=0; i<strlen(str); i++){
            //std::cout << str[i] << std::endl;
            cti_it = char_to_index.find(str[i]); 
            if(cti_it != char_to_index.end() && cti_it->second >= head){
                head = cti_it->second;
                cti_it->second = i+1;
                count = i - head + 1; 
            } else {
                if(cti_it != char_to_index.end()){
                    cti_it->second = i+1;
                } else {
                    char_to_index.insert(std::pair<char, int>(str[i], i+1));
                }
                count++;
            }
            if(result < count){
                result = count;
            }
        }
        return result;
    }
};
