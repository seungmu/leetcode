#include <vector>
class Solution {
public:
   int singleNumber(std::vector<int>& nums) {
      int k=0;
      for(auto it=nums.begin(); it!=nums.end();it++){
         int i=*it;
         k ^= i;
      }
      return k;
    }
};
