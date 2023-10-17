#include<iostream>
#include<vector>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node* link;
};

template <typename T>
class Queue{
	private:
		Node<T>* front;
		Node<T>* rear;
	
	public:
		void Create() {
			this->front = this->rear = NULL;
		}

		bool IsEmpty() {
			if(front == NULL && rear == NULL) return true;
			return false;
		}

		void Enqueue(T x) {
			Node<T>* newNode = new Node<T>;
			newNode->data = x;
			newNode->link = NULL;
			if(front == NULL) front = rear = newNode;
			else {
				rear->link = newNode;
				rear = newNode;
			} 
		}

		void Dequeue() {
			Node<T>* temp = front;
			if(front == NULL) {
				cout << "The Queue is Empty\n" << endl;
				return;
			}
			if(front == rear) front = rear = NULL;
			else front = front->link;
			delete(temp);
		} 

		T Front() {
			return front->data;
		} 
};

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};

BSTNode* getNewNode(int x) {
	BSTNode* newNode = new BSTNode;
	newNode->data = x;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}

BSTNode* Insert(BSTNode* rootPtr, int x) {
	if(rootPtr == NULL) rootPtr = getNewNode(x);
	else if(x <= rootPtr->data) rootPtr->left =  Insert(rootPtr->left, x);
	else rootPtr->right = Insert(rootPtr->right, x);
	return rootPtr;
}

void InsertInLevelOrder(BSTNode* &rootPtr, int arr[], int size) {
	BSTNode* temp;
	for(int i=0; i<=(size-2)/2; i++) {
		if(rootPtr == NULL) {
			rootPtr = getNewNode(arr[i]);	
		}

		temp = rootPtr;
		while(temp->data != arr[i]) {
			temp = temp->left;
			if(temp == NULL) break;
		}
		if(temp != NULL) {
			temp->left = getNewNode(arr[2*i+1]);
			if(2*i+2 < size) {
				temp->right = getNewNode(arr[2*i+2]);
			}
			continue;
		} 

		temp = rootPtr;
		while(temp->data != arr[i]) {
			temp = temp->right;
			if(temp == NULL) break;
		}
		if(temp != NULL) {
			temp->left = getNewNode(arr[2*i+1]);
			if(2*i+2 < size) {
				temp->right = getNewNode(arr[2*i+2]);
			}
			continue;
		} 
		
	}
}

void PrintLevelOrder(BSTNode* rootPtr) {
	if(rootPtr == NULL) return;
	Queue<BSTNode*> Q;
	Q.Create();
	Q.Enqueue(rootPtr);
	while(!Q.IsEmpty()) {
		BSTNode* current = Q.Front();
		Q.Dequeue();

		cout << current->data << " ";
		
		if(current->left != NULL) Q.Enqueue(current->left);
		if(current->right != NULL) Q.Enqueue(current->right);
	}
	cout << endl;
}

void PrintNodesWhoseValuesAreLessThanTheirChildren(BSTNode* rootPtr) {
	if(rootPtr==NULL) return;
	Queue<BSTNode*> Q;
	Q.Create();
	Q.Enqueue(rootPtr);
	while(!Q.IsEmpty()) {
		BSTNode* current = Q.Front();
		Q.Dequeue();

		BSTNode* left = current->left;
		BSTNode* right = current->right;
		int leftdata=0;
		int rightdata=0;
		if(left != NULL) {
			leftdata = left->data;
			Q.Enqueue(left);
		} 
		if(right != NULL) {
			rightdata = right->data;
			Q.Enqueue(right);
		} 
		if(leftdata + rightdata > current->data) cout << current->data << " ";
	}
	cout << endl;
}

void Preorder(BSTNode* rootPtr, vector<int>& v) {
	if(rootPtr == NULL) return;

	v.push_back(rootPtr->data);
	Preorder(rootPtr->left, v);
	Preorder(rootPtr->right, v);
}

void Inorder(BSTNode* rootPtr, vector<int>& v) {
	if(rootPtr == NULL) return;
	
	Inorder(rootPtr->left, v);
	v.push_back(rootPtr->data);
	Inorder(rootPtr->right, v);
}

void Postorder(BSTNode* rootPtr, vector<int>& v) {
	if(rootPtr == NULL) return;
	
	Postorder(rootPtr->left, v);
	Postorder(rootPtr->right, v);
	v.push_back(rootPtr->data);
}

bool match(vector<int> v1, vector<int> v2) {
	for(int i=0; i<v1.size(); i++) {
		if(v1[i] != v2[i]) return false;
	}
	return true;
}

void checkTraversal(BSTNode* rootPtr, vector<int> v) {
	vector<int> inorder;
	vector<int> preorder;
	vector<int> postorder;
	
	Inorder(rootPtr, inorder);
	Preorder(rootPtr, preorder);
	Postorder(rootPtr, postorder);

	if(match(v, inorder)) cout << "It is a valid In-order traversal." << endl;
	else if(match(v, preorder)) cout << "It is a valid Pre-order traversal." << endl;
	else if(match(v, postorder)) cout << "It is a valid Post-order traversal." << endl;
	else cout << "Invalid traversal";

}

int main() {
	BSTNode* rootPtr = NULL;
	int arr[8]{0};
	int n;
	for(int i=0; i<8; i++) {
		cin >> n;
		// rootPtr = Insert(rootPtr, n);
		arr[i] = n;
	}

	InsertInLevelOrder(rootPtr, arr, 8);

	cout << "===============================================" << endl;

	PrintLevelOrder(rootPtr);

	cout << "===============================================" << endl;

	PrintNodesWhoseValuesAreLessThanTheirChildren(rootPtr);

	cout << "===============================================" << endl;

	cout << "Enter the sequence: ";
	vector<int> v;
	for(int i=0; i<8; i++) {
		cin >> n;
		v.push_back(n);
	}

	checkTraversal(rootPtr, v);
}