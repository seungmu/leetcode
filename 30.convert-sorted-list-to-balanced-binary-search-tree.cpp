struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
    TreeNode *result = NULL;
		ListNode *lnode = NULL;
		int minimum_depth, maximum_depth;
		for(lnode= head; lnode; lnode = lnode->next){
			insert_element(result, lnode);
			balance_tree(result);
		}
		for(int i=0;i< 10; i++){
      maximum_depth = 0;
      minimum_depth = 0;
			minimum_depth = get_minimum_depth(result, 0);
			get_maximum_depth(result, maximum_depth, 0);
			if(maximum_depth - minimum_depth >= 2){
				balance_tree(result);
			} else {
				break;
			}
		}
    return result;
	}

	int get_minimum_depth(TreeNode* node, int current_depth){
		int left_depth = 0, right_depth = 0;
		if(!node){
			return 0;
		}
		current_depth++;
		if(node->left){
			left_depth = get_minimum_depth(node->left, current_depth);
		}
		if(node->right){
			right_depth = get_minimum_depth(node->right, current_depth);
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

	void get_maximum_depth(TreeNode* node, int &depth, int current_depth){
		if(!node){
			return;
		}
		current_depth++;
		if(depth < current_depth){
			depth = current_depth;
		}
		if(node->left){
			get_maximum_depth(node->left, depth, current_depth);
		}
		if(node->right){
			get_maximum_depth(node->right, depth, current_depth);
		}
	}

	void insert_element(TreeNode *&node, ListNode *lnode){
		TreeNode *element = new TreeNode(lnode->val);
		if(node == NULL){
			node = element;
		} else {
			insert_element(node->right, lnode);
		}
	}

	void rRotate(TreeNode* &node){
		TreeNode *p = node->left;
		node->left = p->right;
		p->right = node;
		node = p;
	}

	void lRotate(TreeNode* &node){
		TreeNode *p = node->right;
		node->right = p->left;
		p->left = node;
		node = p;
	}
	
	int balance_tree(TreeNode* &node){
		int left_depth = 0, right_depth = 0;
		if(!node){
			return 0;
		}

		if(node->left){
			left_depth = balance_tree(node->left);
		}
		if(node->right){
			right_depth = balance_tree(node->right);
		}
		if(right_depth-left_depth >= 2){
			lRotate(node);
		} else if (right_depth-left_depth<= -2){
			rRotate(node);
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

