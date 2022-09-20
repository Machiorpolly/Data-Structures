/*** A Binary Tree ***/

#include <iostream>

struct TreeNode {
	int data {};
	TreeNode* left;
    TreeNode* right;

	TreeNode(int value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};

void inorder(TreeNode* root) {
	if (!root) return;

	inorder(root -> left);
	std::cout << root -> data << ' ';
	inorder(root -> right);

	return;
}

void preorder(TreeNode* root) {
	if (!root) return;

	std::cout << root -> data << ' ';
	preorder(root -> left);
	preorder(root -> right);

	return;
}

void postorder(TreeNode* root) {
	if (!root) return;

	postorder(root -> left);
	postorder(root -> right);
	std::cout << root -> data << ' ';

	return;
}

int countNodes(TreeNode* root) {
	int x {0}, y {0};

	if (root) {
		x = countNodes(root -> left);
		y = countNodes(root -> right);
		return x + y + 1;
	}
	return 0;
}

int height(TreeNode* root) {
	if (root == NULL) return 0;

	int lheight { height(root -> left) };
	int rheight { height(root -> right) };

	return 1 + std::max(lheight, rheight);
}

int main() {
	TreeNode* root = new TreeNode(1);

	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);

	root -> left -> left = new TreeNode(4);

	std::cout << "Inorder of the TreeNode is: ";
	inorder(root);
	std::cout << '\n';

	std::cout << "Preorder of the TreeNode is: ";
	preorder(root);
	std::cout << '\n';

	std::cout << "Postorder of the TreeNode is: ";
	postorder(root);
	std::cout << '\n';

	std::cout << "Number of nodes in the tree is: " << countNodes(root) << '\n';

	std::cout << "Height of the tree is: " << height(root) << '\n';
	return 0;
}
