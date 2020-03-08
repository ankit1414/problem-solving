#include<iostream>
#include <queue>
using namespace std;

class node{

public: 
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = right = NULL;
	}

};

node* buildTreeFromArray(int *arr,int s,int e){
	node* root;
	if(s == e){
		return new node(arr[s]);
	}

	int mid = (s+e)/2;
	root = new node(arr[mid]);
	root->left = buildTreeFromArray(arr,s,mid-1);
	root->right = buildTreeFromArray(arr,mid+1,e);

	return root;

}
// level order printing of tree; (minor changes to bfs() code)
void levelOrder(node * root){
	cout<<endl;

	queue<node*> maintainer;
	maintainer.push(root);
	maintainer.push(NULL);
	while(!maintainer.empty()){
		node* temp = maintainer.front();
		if(temp){
			cout<<temp->data<<", ";
			maintainer.pop();
			if(temp->left)
				maintainer.push(temp->left);
			if(temp->right)
				maintainer.push(temp->right);

		} else {
			maintainer.pop();
			cout<<endl;
			if(!maintainer.empty()){
				maintainer.push(NULL);
			}
		}
	}
}


int main(){

	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(int);
	node* root = buildTreeFromArray(arr,0,n-1);
	levelOrder(root);

	return 0;
}