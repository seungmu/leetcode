struct ListNode {
  int val;
  ListNode *next;
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		int temp;
		ListNode *p1, *p2;
		for (p1 = head, p1? p2 = head->next: p2=NULL; p1 != NULL && p2 != NULL;)
		{
			temp = p1->val;
			p1->val = p2->val;
			p2->val = temp;
			if(p2->next == NULL){
				p1 = NULL;
			} else {
				p1 = p2->next;
			}
			if(p1 != NULL){
				p2 = p1->next;
			} else {
				p2 = NULL;
			}
		}
		return head;
	}
};
