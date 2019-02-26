#include <algorithm>
class Solution {
public:
    int climbStairs(int n) {
			int numOf2 = n/2, numOf1 = n%2;
			int numOfNumbers = numOf2 + numOf1, sum = 0;
			while(numOf2>0) {
				int minNum = std::min(numOf1, numOf2);
				int top=1, bottom = 1;
				for(int i = 0; i<minNum; i++){
					top *= numOfNumbers-i;
					bottom *= i+1;
				}
				sum += top / bottom;
				numOf2 --;
				numOf1 += 2;
			}
			return sum;
    }
};
