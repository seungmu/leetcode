#include <vector>
#include <string>
#include <iostream>
class Solution {
public:
    void reverseWords(std::string &s) {
        std::vector<std::string> vec_str;
        std::string str;
        char c=' ';
        int i=0, j=0;
        do{
            j = s.find(c, i);
            if(i!=j)
                str = s.substr(i, j>0? j-i:s.length()-i);
                if(!str.empty()){
             //       std::cout << str << "@@@" << std::endl;
                    vec_str.push_back(str);
                }
            //std::cout << i << "###" << j << "@@@" << std::endl;
            i=j+1;
            str.erase(0, str.length());
        } while (j<s.length());
        s.erase(0, s.length());
        for(;vec_str.size()>0; vec_str.pop_back()){
            s += vec_str.back();
            //std::cout << s << "##"<< std::endl;
            if(vec_str.size() > 1){
                s += " ";
            }
        }
    }
};

int main(){
    Solution s;
    std::string str = "   1   ";
    s.reverseWords(str);
    std::cout << "str:" << str << std::endl;
}
