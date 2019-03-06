
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

#include <vector>
bool visit_left_first(TreeNode* node, std::vector<int> &valueArray, TreeNode* root, bool &is_left_part);
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       std:: vector<int> valueArray;
       bool is_left_part = true;
       return (visit_left_first(root, valueArray, root, is_left_part) && valueArray.empty());

        
    }
};

bool visit_left_first(TreeNode* node, std::vector<int> &valueArray, TreeNode* root, bool &is_left_part){
   if(node == NULL) return true;
   bool result2 = true;
   bool result1 = visit_left_first(node->left, valueArray, root, is_left_part);
   if(node != root){
      if(is_left_part)
         valueArray.push_back(node->val);
      else {
         if(!valueArray.empty()){
            int value = valueArray.back();
            valueArray.pop_back();
            if(value != node->val)
               result2 =  false;
         } else {
            result2 = false;
         }
      }
   } else {
      is_left_part = false;
   }
   bool result3 = visit_left_first(node->right, valueArray, root, is_left_part);
   return (result1 && result2 && result3);
}
