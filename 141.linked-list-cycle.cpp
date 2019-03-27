
struct ListNode {
  int val;
  ListNode *next;
   //ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
       if(head == NULL) return false;
       ListNode *runner, *fastRunner;
       runner = head;
       fastRunner = runner->next;
       while(fastRunner!=NULL){
          if(fastRunner == runner) return true;
          if(fastRunner == NULL) return false;
          fastRunner = fastRunner->next;
          if(fastRunner == runner) return true;
          if(fastRunner == NULL) return false;
          fastRunner = fastRunner->next;
          runner = runner->next;
       }
       return true;
        
    }
};
