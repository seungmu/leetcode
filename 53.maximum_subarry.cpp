#include <vector>
#include <algorithm>

class Solution {
public:
   int maxSubArray(std::vector<int>& nums) {
      int ans = nums[0], sum = 0;
      for (int i = 0; i< int(nums.size()); i++){
         sum += nums[i];
         ans = std::max(sum, ans);
         sum = std::min(sum, 0);
      }
      return ans;
    }
};
