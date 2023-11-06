#include<iostream>
#include<queue>

using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};

BSTNode* rootPtr = NULL;

BSTNode* getNewNode(int x) {
	BSTNode* newNode = new BSTNode;
	newNode->data = x;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}

void heapify(int arr[], int i) {
	
}

void insertKey(int x) {
	BSTNode* newNode = getNewNode(x);
	queue<BSTNode*> Q;
	Q.push(rootPtr);
	while(Q.front() != NULL) {
		BSTNode* temp = Q.front();
		Q.push(temp->left);
		Q.push(temp->right);
		Q.pop();
	}
	
}
