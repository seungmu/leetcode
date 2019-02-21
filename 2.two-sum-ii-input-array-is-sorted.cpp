#include <vector>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::vector<int> index;
        for(int i=0; i<numbers.size(); i++){
            int k = binary_search(numbers, target-numbers[i], i);
            if(k>0){
                index.push_back(i+1);
                index.push_back(k+1);
            }
        }
        return index;
    }

    int binary_search(std::vector<int>& numbers, int key, int start){
        int l=start+1, r=numbers.size()-1;
        while(r>l){
            int m = (r + l) / 2;
            if(numbers[m] < key){
                l = m+1;
            } else {
                r = m;
            }
        }
        return (l==r && numbers[l] == key)? l: -1;
    }
};
