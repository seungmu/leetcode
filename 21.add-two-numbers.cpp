

#include <stdlib.h>
#include <iostream>
struct ListNode {
     int val;
     ListNode *next;
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *p1, *p2, *prev, *result = NULL, *p3;
			int add_on = 0;
			for (p1 = l1, p2 = l2; p1 != NULL || p2 != NULL; )
			  {
					p3 = (ListNode *) malloc(sizeof(ListNode));
					p3->next = NULL;
					if(p1 && p2){
						p3->val = p1->val + p2->val + add_on;
						p1 = p1->next;
						p2 = p2->next;
					} else if (p1){
						p3->val = p1->val + add_on;
						p1 = p1->next;
					} else if (p2){
						p3->val = p2->val + add_on;
						p2 = p2->next;
					}
          std::cout << p3->val << std::endl;
						if(p3->val >9){
								add_on = 1;
								p3->val = p3->val %10;
						} else {
								add_on = 0;
						}
						if(result == NULL){
							result = p3;
						} else {
							prev->next  = p3;
						}
						prev = p3;
				}
      if(add_on){
        p3 = (ListNode *) malloc(sizeof(ListNode));
        p3->next = NULL;
        p3->val = add_on;
        if(result == NULL){
          result = p3;
        } else {
          prev->next  = p3;
        }
      }
			return result;
    }
};
