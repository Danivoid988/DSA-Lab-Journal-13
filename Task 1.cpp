#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}


};

	node* insertnod(int val, node* root) {
		if (root == NULL) {

			return new node(val);
		}
		if (val < root->data) {
			root->left = insertnod(val, root->left);
		}
		else {
			root->right = insertnod(val, root->right);
		}
		return root;
	}

	void inorder(node* root) {

		if (root != NULL) {
			inorder(root->left);
			cout << root->data << "  ";
			inorder(root->right);
		}
	}
	void searchee(node* root,int key) {

		if (root != NULL) {
		 
			searchee(root->left,key);
			if (key == root->data) {
				cout << "the key is found " << endl;
			}
			searchee(root->right,key);
		}
	}
	node* inordersuc(node* root) {
		node* curr = root;
		while (curr && root->left != NULL) {
			curr = curr->left;
		}
		return curr;

	}
	node* deleteinsbst(node* root, int value) {

		if (value < root->data) {
			root->left=deleteinsbst(root->left, value);
		}
		else if (value > root->data) {
			root->right = deleteinsbst(root->right, value);
		}
		else {
			if (root->left == NULL) {
				node* temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right == NULL) {
				node* temp = root->left;
				free(root);
				return temp;
			}
			
			node* temp = inordersuc(root->right);
			root->data = temp->data;
			root->right = deleteinsbst(root->right, temp->data);
		}
		return root;
	}
	void main() {

		node* root = NULL;
		root = insertnod(5, root);
		insertnod(1,root);
		insertnod(3, root);
		insertnod(2, root);
		insertnod(4, root);
		insertnod(7, root);
		

		inorder(root);

		cout << endl;
		searchee(root, 9);
		root = deleteinsbst(root, 3);

		cout << endl;

		inorder(root);
		system("pause");
	}
