#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool checkTree(TreeNode* root) {
	if (root == nullptr) return false;
	if (root->left == nullptr || root->right == nullptr) return false;
	return root->val == (root->left->val + root->right->val);
}

int main() {
	TreeNode* leftChild = new TreeNode(2);
	TreeNode* rightChild = new TreeNode(3);
	TreeNode* root = new TreeNode(5, leftChild, rightChild);

	if (checkTree(root)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}

	delete leftChild;
	delete rightChild;
	delete root;
}