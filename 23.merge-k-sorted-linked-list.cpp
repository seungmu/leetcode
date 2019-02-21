#include <vector>
struct ListNode {
  int val;
	ListNode *next;
};

class Solution {
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		ListNode *result=NULL;

		if(lists.size() == 0){
			return result;
		} 

		result = lists[0];
		for (unsigned long i = 1; i < lists.size(); ++i)
		{
			result = mergeTwoLists(result, lists[i]);
		}
		return result;
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
