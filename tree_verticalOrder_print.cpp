#include<iostream>
#include<map>
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
node* buildTree(int i,int level){
	node* root= NULL;
	int n;
	cin>>n;
	
	
}
int main() {
	int level;
	cin>>level;
	node* root = buildTree(0,level);
	return 0;
}