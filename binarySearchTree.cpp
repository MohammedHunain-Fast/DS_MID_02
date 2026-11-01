#include <iostream>
using namespace std;
#define MAX 14

class Node {
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int data) : data(data), left(NULL), right(NULL) {
		}
};
class Queue {
	public:
		Node* arr[MAX];
		int front;
		int rear;
		int count;
		
		Queue() : front(-1), rear(-1), count(0) {
		}
		void enqueue(Node* data) {
			if(rear == MAX - 1) {
				return;
			}
			count++;
			if(rear == -1) {
				arr[++rear] = data;
				front++;
				return;
			}
			arr[++rear] = data;
		}
		void dequeue() {
            if(front == -1 || front > rear) return;
            front++;
            count--;
        }

        bool isEmpty() {
            return (front == -1 || front > rear);
        }
        bool isFull() {
            return (rear == MAX - 1);
        }
        Node* peek() { 
        	if(front == -1 || front > rear) return NULL;
            return arr[front];
        }
};

Node* insert(Node* root, int val) {
	if(root == NULL) return new Node(val);
	if(val < root -> data) {
		root -> left = insert(root -> left, val);
	}
	else {
		root -> right = insert(root -> right, val);
	}
	return root;
}


Node* buildTree(int arr[], int n) {
	int i;
	Node* root = NULL;
	for(i = 0; i < n; i++) {
		root = insert(root, arr[i]);
	}
	return root;
}

bool search(Node* root, int key) {
	if(root == NULL) return false;
	if(root -> data == key) return true;
	if(key < root -> data) return search(root -> left, key);
	else search(root -> right, key);
	
}

void preOrderTraversal(Node* root) {
	if(root == NULL) return;
	cout << root -> data << " ";
	preOrderTraversal(root -> left);
	preOrderTraversal(root -> right);
}

void inOrderTraversal(Node* root) {
	if(root == NULL) return;
	inOrderTraversal(root -> left);
	cout << root -> data << " ";
	inOrderTraversal(root -> right);
}

void postOrderTraversal(Node* root) {
	if(root == NULL) return;
	postOrderTraversal(root -> left);
	postOrderTraversal(root -> right);
	cout << root -> data << " ";
}

void levelOrderTraversal(Node* root) {
	if (root == NULL) return;

	Queue q;
	q.enqueue(root);

	while (!q.isEmpty()) {
		int levelSize = q.count; 
		int i;
		for(i = 0; i < levelSize; i++) {
			Node* curr = q.peek();
			q.dequeue();

			cout << curr->data << " ";

			if (curr->left != NULL) {
				q.enqueue(curr->left);
			}
			if (curr->right != NULL) {
				q.enqueue(curr->right);
			}
		}
		cout << endl;
	}
}

Node* getInOrderSuccessor(Node* root) {
	while(root != NULL && root -> left != NULL) root = root -> left;
	return root;
}

Node* delNode(Node* root, int key) {
	if(root == NULL) return NULL;
	if(key < root -> data) root -> left = delNode(root -> left, key);
	else if(key > root -> data) root -> right = delNode(root -> right, key);
	else {
		if(root -> left == NULL) {
			Node* temp = root;
			delete root;
			return temp;
		}
		else if(root -> right == NULL) {
			Node* temp = root;
			delete root;
			return temp;
		}
		else {
			Node* IS = getInOrderSuccessor(root -> right);
			root -> data = IS -> data;
			root -> right = delNode(root -> right, IS -> data);
		}
	}
	return root;
}


int main() {
	int arr[] = {3, 2, 1, 5, 4, 6};
	Node* root = buildTree(arr, 6);
//	preOrderTraversal(root);
//	cout << endl;
	inOrderTraversal(root);
	cout << endl;
	cout << search(root, 1);
	cout << endl;
//	postOrderTraversal(root);
//	cout << endl;
//	levelOrderTraversal(root);
	inOrderTraversal(root);
	cout << endl;
	root = delNode(root, 5);
	inOrderTraversal(root);
	cout << endl;
	return 0;
}
