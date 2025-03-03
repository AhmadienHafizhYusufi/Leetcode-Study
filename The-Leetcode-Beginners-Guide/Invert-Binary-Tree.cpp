#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
	if (root == nullptr) return nullptr;

	// Swap the left and right children
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;

	// Recursively invert the left and right subtrees
	invertTree(root->left);
	invertTree(root->right);

	return root;
}

void printTree(TreeNode* root) {
	if (root == nullptr) return;
	cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}

int main() {
	// Create a sample tree:
	//     4
	//    / \
	//   2   7
	//  / \ / \
	// 1  3 6  9
	TreeNode* leftChild = new TreeNode(2, new TreeNode(1), new TreeNode(3));
	TreeNode* rightChild = new TreeNode(7, new TreeNode(6), new TreeNode(9));
	TreeNode* root = new TreeNode(4, leftChild, rightChild);

	cout << "Original tree: ";
	printTree(root);
	cout << endl;

	// Invert the tree
	invertTree(root);

	cout << "Inverted tree: ";
	printTree(root);
	cout << endl;

	// Clean up memory
	delete leftChild->left;
	delete leftChild->right;
	delete rightChild->left;
	delete rightChild->right;
	delete leftChild;
	delete rightChild;
	delete root;

	return 0;
}