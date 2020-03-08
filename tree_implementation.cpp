#include<iostream>
#include<queue>
#include <climits>

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
//this build function is preorder build function;
node* buildTree(){
	int d;
	cin>>d;

	//base case
	if(d == -1){
		return NULL;
	}

	node * root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}
//this print function is preorder print ;
void printPreorder(node* root){
	//base case
	if(root == NULL)
		return;
	//recursive case
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
	return;
}
void printInorder(node *root){
	//base case
	if(root == NULL)
		return;
	//recursive case
	
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
	return;
}
void printPostorder(node* root){
	//base case
	if(root == NULL)
		return;
	//recursive case
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<" ";
	return;

}
//print k-th level
void printKthLevel(node* root, int k){

	//base case
	if(root == NULL){
		return;
	}

	if(k == 1){
		cout<<root->data<<" ";
		return;
	}

	printKthLevel(root->left , k-1);
	printKthLevel(root->right, k-1);
	return;
}
// this level order algo takes O(n^2) time (better use queue method which takes O(N) )
void levelOrderRec(node* root,int h,int i=1){
	//base case
	if(i>h){
		return;
	}

	printKthLevel(root,i);
	cout<<endl;
	levelOrderRec(root,h,i+1);
}

// bfs of the tree ( can be modified for level order printing)
void bfs(node* root){

	cout<<endl;

	queue<node*> maintainer;
	maintainer.push(root);
	while(!maintainer.empty()){
		node* temp = maintainer.front();
		cout<<temp->data<<", ";
		maintainer.pop();
		if(temp->left)
			maintainer.push(temp->left);
		if(temp->right)
			maintainer.push(temp->right);
	}


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
//height of tree
int height(node *root){
	//base case
	if(root == NULL){
		return 0;
	}
	//recursive case
	int heightOfLeft = height(root->left);
	int heightOfRight = height(root->right);
	return max(heightOfLeft,heightOfRight)+1;
}

// diameter of the tree
// this approach is O(n^2) bcoz at every node we are calc height which isnt efficient
// this is top down approach 
// instead we can use bottom up approach i.e postorder traversal nd will return height along with diameter
// this will optimize our current solution.
int diameter(node *root){
	//base case
	if(root == NULL){
		return 0;
	}

	//recursive case
	int h1 = height(root->left);
	int h2 = height(root->right);

	int op1 = h1+h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1, max(op2,op3));


}
// i m assuming pair.first as height and pair.second as diameter
pair<int,int> fastDiameter(node* root){
	pair<int,int> p;
	//base case
	if(root == NULL){
		p.first = p.second = 0;
		return p;
	}


	pair<int,int> pLeft = fastDiameter(root->left);
	pair<int,int> pRight = fastDiameter(root->right);
	p.first = max(pLeft.first,pRight.first) + 1;
	p.second = max(pLeft.first+pRight.first , max(pLeft.second,pRight.second));
	return p;
}
// number of nodes
int countNodes(node* root){
	//base case
	if(root == NULL){
		return 0;
	}
	// recursive case 
	int nodesInLeft = countNodes(root->left);
	int nodesInRight = countNodes(root->right);
	return nodesInLeft + nodesInRight + 1;
}
// returns the sum of nodes
int sumAllNodes(node* root){
	//base case
	if(root == NULL){
		return 0;
	}
	//recursive case
	int sumOfLeft = sumAllNodes(root->left);
	int sumofRight = sumAllNodes(root->right);
	return sumofRight+sumOfLeft+root->data;
}
// function to replace each node by sum of child nodes
int replace_with_sum(node *root){
	//base case
	if(root == NULL){
		return 0;
	}

	int data = root->data;
	int val1 = replace_with_sum(root->left);
	int val2 = replace_with_sum(root->right);
	root->data = val1+val2;
	if(root->left==NULL && root->right== NULL){
		root->data = data;
	}
	return val1+val2+data;
}

// function to check if the tree is balanced or not
// pair.first is height and pair.second is bool(true/false for balanced or not)
pair<int,bool> isBalancedHelper(node * root){
	pair<int,bool> p;
	//base case
	if(root == NULL){
		p.first = 0;
		p.second = true;
		return p;
	}

	auto l = isBalancedHelper(root->left);
	auto r = isBalancedHelper(root->right);

	p.first = max(l.first ,r.first) +1;
	if(abs(l.first-r.first)<=1 && l.second && r.second){
		p.second = true;
	}
	else
		p.second = false;
	return p;
}
bool isBalanced(node* root){
	// we can also print / return the address of the unbalanced node using slight modification in the helper fucntion.
	auto i = isBalancedHelper(root);
	bool check = i.second;
	return check;
}
bool isBst(node * root,int minv = INT_MIN, int maxv = INT_MAX){
	//base case
	if(root == NULL){
		return true;
	}
	
	// recursive case
	if(root->data >= minv 
		and root->data <= maxv 
		and isBst(root->left,minv,root->data) 
		and isBst(root->right,root->data,maxv))
			return true;
	else
		return false;
}

int main(){
	cout<<"Enter the elemets of the tree: \n";
	node* root = buildTree(); // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
	cout<<"Printing nodes: ";
	printPreorder(root);
	cout<<endl;
	cout<<"height of the tree is : "<<height(root)<<endl;
	//cout<<"Printing kth level : \n";
	//printKthLevel(root,2);
	//FOR LEVELORDER traversal (do print kth level orderwise);
	//levelOrderRec(root ,height(root));
	cout<<endl;
	cout<<"BFS : ";
	bfs(root);
	cout<<endl;
	cout<<"Level order : ";
	levelOrder(root);
	cout<<"\nTotal nodes : "<<countNodes(root)<<endl;
	cout<<"\nSum of nodes: "<<sumAllNodes(root)<<endl;
	cout<<"diameter of the tree: "<<diameter(root)<<endl;
	auto p = fastDiameter(root);
	cout<<"Fast diameter : "<<p.second<<endl;

	cout<<"Replacing with sum :\n";
	replace_with_sum(root);
	cout<<"Level order : ";
	levelOrder(root);
	
	if(isBalanced(root))
		cout<<"tree is balanced\n";
	else
		cout<<"tree is not balanced\n";
	if(isBst(root)){
		cout<<"root: tree is bst\n";
	}
	else 
		cout<<"root: tree is not bst\n";
	cout<<endl;
	node* newroot = buildTree(); // 8 6 2 -1 -1 7 -1 -1 10 9 -1 -1 12 -1 -1
	if(isBst(newroot)){
		cout<<"root: tree is bst\n";
	}
	else 
		cout<<"root: tree is not bst\n";
	return 0;
}