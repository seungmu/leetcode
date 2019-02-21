#include <vector>
#include <stdlib.h>
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      std::vector<int> random_index;
      RandomListNode *result = NULL, *p, *p2, *p_prev;
      if(head == NULL){
        return head;
      }
      for (p=head; p!=NULL;){
        p2 = (RandomListNode *)malloc(sizeof(RandomListNode));
			  p2->label = p->label;
        p2->next = NULL;
        p2->random = NULL;
			  p2->random = p->random;
			  //random_index.push_back(p->random->label);
			  if(result == NULL) {
			  	result = p2;
			  } else {
			  	p_prev->next = p2;
			  }
			  p_prev = p2;
        p = p->next;
      }
      for (p= result; p; p=p->next){
        for(p2=result; p2; p2=p2->next){
          if(p->random != NULL && p2->label == p->random->label)
            p->random = p2;
        }
      }
      return result;
    }
};
