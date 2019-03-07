#include <vector>
#include <map>
#include <iostream>
class Solution {
public:
   static bool compare(std::pair<int, int> &a, std::pair<int, int> &b){
      return a.first < b.first;
   }

   int maxProfit(std::vector<int>& prices) {
      std::vector<std::pair<int, int> > priceDateMap;
      int maxInterest = 0;
      int numOfDays = prices.size();
      for(int i=0; i<numOfDays; i++){
         priceDateMap.push_back(std::pair<int, int>(prices[i], i));
      }
      std::sort(priceDateMap.begin(), priceDateMap.end(), compare);
      for(auto it1 = priceDateMap.begin(); it1!=priceDateMap.end(); it1++){
         for(auto it2=(--priceDateMap.end()); it2!=it1; it2--){
            if(it1->second < it2->second){
               if(it2->first - it1->first > maxInterest){
                  maxInterest = it2->first - it1->first;
                  break;
               }
            }
         }
      }
      return maxInterest;
   }
};
