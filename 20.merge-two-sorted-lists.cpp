#include <stdlib.h>
struct ListNode {
     int val;
     ListNode *next;
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			ListNode *p1, *p2, *result=NULL, *p3, *p3_prev=NULL;
			for (p1 = l1, p2 = l2; p1!=NULL || p2!=NULL; p3_prev = p3) {
				p3= (ListNode *)malloc(sizeof(ListNode));
				if(p1 && p2){
						if(p1->val >= p2->val){
								p3->val = p2->val;
								p2 = p2->next;
						} else {
								p3->val = p1->val;
								p1 = p1->next;
						}
				} else if(p1 == NULL){
						p3->val = p2->val;
						p2 = p2->next;
				} else if(p2 == NULL){
						p3->val = p1->val;
						p1 = p1->next;
				}
				p3->next = NULL;
				if(!result){
						result = p3;
				} else {
						p3_prev->next = p3;
				}
			 }
				return result;
    }
	//This version is much more better since no dynamic memory is allocated
	ListNode* mergeTwoLists_2(ListNode* l1, ListNode* l2) {
		ListNode *p1, *p2, *result=NULL, *p3, *p3_prev=NULL;
		for (p1 = l1, p2 = l2; p1!=NULL || p2!=NULL; p3_prev = p3) {
			if(p1 && p2){
				if(p1->val >= p2->val){
					p3 = p2;
					p2 = p2->next;
				} else {
					p3 = p1;
					p1 = p1->next;
				}
			} else if(p1 == NULL){
				p3 = p2;
				p2 = p2->next;
			} else if(p2 == NULL){
				p3 = p1;
				p1 = p1->next;
			}
			if(!result){
				result = p3;
			} else {
				p3_prev->next = p3;
			}
		}
		return result;
	}
};
