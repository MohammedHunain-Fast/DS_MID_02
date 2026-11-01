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

static int idx = -1;
Node* buildTree(int preOrder[]) {
	idx++;
	if(preOrder[idx] == -1) return NULL;
	Node* root = new Node(preOrder[idx]);
	root -> left = buildTree(preOrder);
	root -> right = buildTree(preOrder);
	return root;
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


int main() {
	int arr[] = {3, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1};
	Node* root = buildTree(arr);
	preOrderTraversal(root);
	cout << endl;
	inOrderTraversal(root);
	cout << endl;
	postOrderTraversal(root);
	cout << endl;
	levelOrderTraversal(root);
	return 0;
}
