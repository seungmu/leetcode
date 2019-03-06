#include <algorithm>
#include <iostream>
class Solution {
public:
    unsigned int climbStairs(int n) {
			int numOf2 = n/2, numOf1 = n%2;
			unsigned int numOfNumbers, sum = 0;
			while(numOf2>=0) {
        numOfNumbers = numOf2 + numOf1;
				int minNum = std::min(numOf1, numOf2);
				unsigned long top=1, bottom = 1;
				for(int i = 0; i<minNum; i++){
					top *= numOfNumbers-i;
          if(top%(i+1) == 0){
            top /= (i+1);
          } else {
					  bottom *= i+1;
          }
				}
				sum += top / bottom;
        //std::cout << sum << std::endl;
				numOf2 --;
				numOf1 += 2;
			}
			return sum;
    }
};
