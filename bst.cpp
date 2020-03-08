#include<iostream>
#include <queue>
using namespace std;

class node{

public:
	int data;
	node* left;
	node* right;

	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}


};
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

node* insertNodeInBst(node* root,int data){
	//base case
	if(root == NULL){
		return new node(data);
	}

	//recursive case;
	if(data<= root->data){
		root->left = insertNodeInBst(root->left , data);

	}
	else if(data > root->data){
		root->right = insertNodeInBst(root->right , data);
	}
	return root;

}

// inorder print of bst
void inorder(node* root){
	if(root == NULL)
		return;

	inorder(root->left);
	cout<<root->data<<", ";
	inorder(root->right);
}
node* buildTree(){
	node *root = NULL;
	int d;
	cin>>d;
	while(d != -1){
		root = insertNodeInBst(root,d);
		cin>>d;

	}
	return root;
}

bool search(node* root , int key){
	if(root == NULL){
		return false;
	}

	if(key == root->data){
		return true;
	}

	else if(key < root->data){
		return search(root->left,key);
	}
	else{
		return search(root->right , key);
	}

}

node* deletenode(node* root, int key){

	if(root == NULL){
		return NULL;
	}

	if(key<root->data){
		root->left = deletenode(root->left,key);
	}
	else if(key > root->data){
		root->right = deletenode(root->right , key);
	}
	else {
		if(root->left == NULL and root->right == NULL){
			delete root;
			return NULL;
		} else if(root->left != NULL and root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		} else if(root->right != NULL and root->left == NULL){
			node* temp = root->right;
			delete root;
			return temp;
		} else {
			node* inSuccessor= root->right;
			while(inSuccessor->left != NULL){
				inSuccessor = inSuccessor->left;
			}
			root->data = inSuccessor->data;
			root->right = deletenode(root->right,inSuccessor->data); // this is crucial (if u try deleting directly insuccesor then this will not work)
																		// i mean inSuccessor = deletenode(inSuccessor, inSuccessor->data);
		}
	}
	return root;
}
int main(){

	node* root = buildTree(); // 81 32 97 44 71 11 54 68 -1
	
	// int key;
	// cout<<"\nkey to search : ";
	// cin>>key;
	// if(search(root,key))	cout<<"present\n";
	// else	cout<<"not present\n";
	levelOrder(root);
	int delKey;
	cout<<"\nnode to delete : ";
	cin>>delKey;
	root = deletenode(root,delKey);
	cout<<"\nafter deletion\n";
	// cout<<"inorder : ";
	// inorder(root);
	cout<<endl;
	levelOrder(root);

	return 0;
}