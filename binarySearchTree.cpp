#include<iostream>
using namespace std;

struct bstNode{
	int data;
	bstNode* left;
	bstNode* right;
};

bstNode* getNewNode(int data){
	bstNode* temp = new bstNode;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}
bstNode* Insert(bstNode* rootPtr, int data){
	
	if(rootPtr == NULL){
		rootPtr = getNewNode(data);
	}else if(data < rootPtr->data){
		rootPtr->left = Insert(rootPtr->left, data);
	}else{
		rootPtr->right = Insert(rootPtr->right, data);
	}
	
	return rootPtr;
}
bool search(bstNode* rootPtr, int data){
	if(rootPtr == NULL) return false;
	else if(rootPtr->data == data) return true;
	else if(data <= rootPtr->data) return search(rootPtr->left, data);
	else return search(rootPtr->right, data);
	
}

int findMin(bstNode* rootPtr){
	
	if(rootPtr == NULL){
		cout<<"Error! Empty tree"<<endl;
		return -1;
	}
	bstNode* temp = rootPtr;
	
	while(temp->left != NULL){
		temp = temp->left;
	} 
	
	return temp->data;
}

int findMax(bstNode* rootPtr){
	if(rootPtr == NULL){
		cout<<"Error! Empty tree"<<endl;
		return -1;
	}
	bstNode* temp = rootPtr;
	
	while(temp->right != NULL){
		temp= temp->right;
	}
	
	return temp->data;
}
int main(){
	bstNode* rootPtr = NULL;
	
	rootPtr = Insert(rootPtr, 10);
	rootPtr = Insert(rootPtr, 20);
	rootPtr = Insert(rootPtr, 27);
	rootPtr = Insert(rootPtr, 107);
	rootPtr = Insert(rootPtr, 36);
	rootPtr = Insert(rootPtr, 2);
	rootPtr = Insert(rootPtr, 7);
	rootPtr = Insert(rootPtr, 290);
	
	
	int num;
	
	cout<<"Enter a number to be searched: ";
	cin>>num;
	if(search(rootPtr, num))
		cout<<"\nFound";
	else
		cout<<"\nNot Found";
		
	cout<<endl<<endl;
	
	cout<<"The min number is "<<findMin(rootPtr)<<endl;
	cout<<"The max number is "<<findMax(rootPtr)<<endl;
	
}
