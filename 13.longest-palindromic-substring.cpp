#include <string>
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string result(1, s[0]), temp; 
        int max_length = 1, result_head=0;
        int head=0, tail=0;
        for(int i=1; i<=s.length()-1; i++){
            if(s[i-1] == s[i+1]){
                head = i-1, tail=i+1;
                expand_str(s, head, tail);
                head++; tail--;
            }
            if(max_length < tail-head+1){
                result_head = head;
                max_length = tail-head+1;
            } 
            if(s[i-1] == s[i]){
                head = i-1, tail=i;
                expand_str(s, head, tail);
                head++; tail--;
            }
            if(max_length < tail-head+1){
                result_head = head;
                max_length = tail-head+1;
            } 
        }
        return s.substr(result_head, max_length);
    }
    void expand_str(std::string str, int &head, int &tail){
        head--; tail++;
        for(; head>=0 && tail <str.length() && (str[head] == str[tail]); head--, tail++);
    }
};
