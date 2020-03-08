#include<iostream>
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
// pair.first is for head and pair.second is for tail;
pair<node*,node*> bst_to_sortedLL(node* root){
	pair<node*,node*> p;
	if(root == NULL){
		p.first = p.second = NULL;
		return p;
	}
	if(root->left== NULL and root->right == NULL){
		p.first = p.second = root;
		return p;
	}
	if(root->left != NULL and root->right == NULL){
		auto temp = bst_to_sortedLL(root->left);
		temp.second->right = root;
		temp.second = root;
		return temp;
	}
	if(root->right != NULL and root->left == NULL){
		auto temp = bst_to_sortedLL(root->right);
		root->right = temp.first;
		temp.first = root;
		return temp;
	}

	auto lft= bst_to_sortedLL(root->left);
	auto rit = bst_to_sortedLL(root->right);

	lft.second->right = root;
	root->right = rit.first;
	p.first = lft.first;
	p.second = rit.second;
	return p;
}
int main(){

	node* root = buildTree();
	auto a = bst_to_sortedLL(root);
	node* head = a.first;
	while(head){
		cout<<head->data<<", ";
		head = head->right;
	}

	return 0;
}