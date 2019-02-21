
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		int depth=0;
		depth = get_depth(root, 0);
		return depth;
		
	}
	int get_depth(TreeNode* node, int current_depth){
		int left_depth = 0, right_depth = 0;
		if(!node){
			return 0;
		}
		current_depth++;
		if(node->left){
			left_depth = get_depth(node->left, current_depth);
		}
		if(node->right){
			right_depth = get_depth(node->right, current_depth);
		}
		if(right_depth == 0 || left_depth == 0){
			if(right_depth == 0){
				return left_depth+1;
			}
			if(left_depth == 0){
				return right_depth+1;
			}
		} else {
			return left_depth>right_depth ? right_depth+1 : left_depth+1;
		}
		
	}
};
