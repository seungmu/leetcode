#include <vector>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		std::vector<int> val_list;
		if(root == NULL){
			return true;
		}
		get_val(root, &val_list);
		for(unsigned long i=0; i<val_list.size()-1; i++){
			if(val_list[i] >= val_list[i+1]){
				return false;
			}
		}
		return true;
	}
	
	void get_val(TreeNode* node, std::vector<int> *val_list){
		if(node->left){
			get_val(node->left, val_list);
		}
		val_list->push_back(node->val);
		if(node->right){
			get_val(node->right, val_list);
		}
	}
};
