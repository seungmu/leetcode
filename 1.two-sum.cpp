#include <map>
#include <vector>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> hash_table;
        std::vector<int> index;
        for(int i=0; i<nums.size(); i++){
            if(hash_table.end()!=hash_table.find(target-nums[i])){
                index.push_back(hash_table[target-nums[i]]);
                index.push_back(i);
                break;
            }
            hash_table[target-nums[i]] = i;
        }       
        return index;
    }
};
