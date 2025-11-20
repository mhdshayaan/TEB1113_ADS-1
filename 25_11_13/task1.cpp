#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		data = value;
		left = right = nullptr;
	}
};

class BinaryTree {
public:
	Node* root;

	BinaryTree() { root = nullptr; }

	Node* insert(Node* node, int value) {
		if (node == nullptr) return new Node(value);
		if (value < node->data)
			node->left = insert(node->left, value);
		else
			node->right = insert(node->right, value);
		return node;
	}

	void inorder(Node* node) {
		if (!node) return;
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}

	void preorder(Node* node) {
		if (!node) return;
		cout << node->data << " ";
		preorder(node->left);
		preorder(node->right);
	}

	void postorder(Node* node) {
		if (!node) return;
		postorder(node->left);
		postorder(node->right);
		cout << node->data << " ";
	}

	void update(Node* node, int oldVal, int newVal) {
		if (!node) return;
		if (node->data == oldVal) node->data = newVal;
		update(node->left, oldVal, newVal);
		update(node->right, oldVal, newVal);
	}

	Node* deleteNode(Node* root, int key) {
		if (!root) return root;
		if (key < root->data)
			root->left = deleteNode(root->left, key);
		else if (key > root->data)
			root->right = deleteNode(root->right, key);
		else {
			if (!root->left)
				return root->right;
			else if (!root->right)
				return root->left;
		 	Node* temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}

		return root;
	}

	Node* minValueNode(Node* node) {
		Node* current = node;
		while (current && current->left != nullptr)
			current = current->left;
		return current;
	}
};

int main() {
    BinaryTree tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    cout << "\nUpdating 40 -> 45..." << endl;
    tree.update(tree.root, 40, 45);
    tree.inorder(tree.root);
    cout << endl;

    cout << "\nDeleting 70..." << endl;
    tree.root = tree.deleteNode(tree.root, 70);
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
