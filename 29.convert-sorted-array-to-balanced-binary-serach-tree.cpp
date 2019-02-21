#include <vector>
#include <iostream>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(std::vector<int>& nums) {
		TreeNode *result=NULL;
		result = get_BST(nums, 0, nums.size()-1);
    //std::cout << result ->val << std::endl;
		return result;
	}

	TreeNode* get_BST(std::vector<int> &nums, int start, int end){
		TreeNode *node;
		if(start > end){
			return NULL;
		}
		int middle = (start + end) / 2;
		node = new TreeNode(nums[middle]);
    std::cout << node->val << " ***" << start << "**"<< end<< std::endl;		
		node->left = get_BST(nums, start, middle-1);
		node->right = get_BST(nums, middle+1, end);
		return node;
	}
};
