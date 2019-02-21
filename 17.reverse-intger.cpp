#include <vector>
#include <limits.h>

class Solution {
public:
    int reverse(int x) {
			std::vector<int> array;
			int  result = 0;

			if(x==0){
				return 0;
			}

			bool plus = x>0;
			while(x!=0){
				array.push_back(x%10);
				x = x / 10;
			}
			result  = array[0];
			for (int i = 1; i<array.size(); i++)
				{
					if(result > INT32_MAX/10){
						result = 0;
						break;
					}
					if(result== INT32_MAX && array[i] >7){
						result = 0;
						break;
					}
					if(result < INT32_MIN/10){
						result = 0;
						break;
					}
					if(result== INT32_MIN && array[i] >-8){
						result = 0;
						break;
					}
					result = result *10 + array[i];
				}

			return result;
        
    }
};
