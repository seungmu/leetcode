#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
			std::string str;
			if(x<0){
				return false;
			}
			while(x!=0){
				str += std::to_string(x%10);
				x = x%10;
			}
      return isPalindrome_s(str);   
    }
		bool isPalindrome_s(std::string s) {
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
