struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		int depth=0;
		get_depth(root, depth, 0);
		return depth;
	}

	void get_depth(TreeNode* node, int &depth, int current_depth){
		if(!node){
			return;
		}
		current_depth++;
		if(depth < current_depth){
			depth = current_depth;
		}
		if(node->left){
			get_depth(node->left, depth, current_depth);
		}
		if(node->right){
			get_depth(node->right, depth, current_depth);
		}
	}
};
