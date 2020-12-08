#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr) return;
		TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};

TreeNode* build(TreeNode* root, int val)
{
	if (root == NULL){
		root = new TreeNode(0);
		root->val = val;
		return root;
	}
	if (val < root->val) 
		root->left = build(root->left, val);
	else if (val > root->val) 
		root->right = build(root->right, val);
	return root;
}

int main()
{
	Solution res;
	vector<int> inArray = { 8, 6, 10, 5, 7, 9, 11 };
	
	TreeNode* head = NULL;
	for (size_t i = 0; i < inArray.size(); i++)
		head = build(head, inArray[i]);

	res.Mirror(head);
	system("pause");
	return 0;
}