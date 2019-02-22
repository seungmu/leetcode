

#include <vector>
#include <string>

class Solution {
public:
   bool isValid(std::string s) {
      std::vector<char> p_queue;
      for (int i = 0; i<s.length(); i++)
         {
            char current_char = s[i];
            if(current_char == '{' || current_char == '[' || current_char == '(') {
               p_queue.push_back(current_char);
            }
            else if(current_char == '}'){
               if(p_queue.size() == 0) return false;
               char tmp_char = p_queue.back();
               p_queue.pop_back();
               if (tmp_char != '{')
                  {
                     return false;
                     
                  }

            }
            else if(current_char == ']'){
               if(p_queue.size() == 0) return false;
               char tmp_char = p_queue.back();
               p_queue.pop_back();
               if (tmp_char != '[')
                  {
                     return false;
                     
                  }
    
            }
            else if(current_char == ')'){
               if(p_queue.size() == 0) return false;
               char tmp_char = p_queue.back();
               p_queue.pop_back();
               if (tmp_char != '(')
                  {
                     return false;
                     
                  }

            }
            
         }
      if (p_queue.size() != 0)
         {
            return false;
            
         }
      return true;
        
   }
};
