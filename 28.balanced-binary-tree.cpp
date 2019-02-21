#include <stdlib.h>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		bool result = true;
		get_depth(root, result);
		return false;
	}
	int get_depth(TreeNode* node, bool &result){
		int left_depth = 0, right_depth = 0;
		if(!node){
			return 0;
		}

		if(node->left){
			left_depth = get_depth(node->left, result);
		}
		if(node->right){
			right_depth = get_depth(node->right, result);
		}
		if(abs(right_depth-left_depth) >1){
			result = false;
		}
		if(right_depth == 0 || left_depth == 0){
			if(right_depth == 0){
				return left_depth+1;
			}
			if(left_depth == 0){
				return right_depth+1;
			}
		} else {
			return left_depth<right_depth ? right_depth+1 : left_depth+1;
		}
	}
};
