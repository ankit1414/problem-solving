#include<iostream>
#include<unordered_map>
using namespace std;

class node{
public:
	char data;
	unordered_map<char,node*> characters;
	bool terminal;

	node(char d){
		data = d;
	}
};

class Trie{
	node* root = new node('\0');

public:
	void insert(char *s){
		node* temp = root;
		for(int i=0; s[i]!='\0'; i++){

			if(temp->characters.count(s[i])){
				temp = temp->characters[s[i]]; 
			}
			else {
				node* t = new node(s[i]);
				temp->characters[s[i]] = t;
				temp = t;
			}
		}
		temp->terminal = true;
	}

	bool find(char *s){
		node* temp = root;
		for(int i=0; s[i]!='\0'; i++){

			if(temp->characters.count(s[i])){
				temp = temp->characters[s[i]];
			}
			else {
				return false;
			}
		}
		return temp->terminal;
	}

};
int main(){
	Trie t;
	char arr[][10] = {"hello", "hell", "horn","apple","ace","appy"};

	for(int i=0; i<6; i++){
		t.insert(arr[i]);
	}
	char f[10];
	cin>>f;
	if(t.find(f)){
		cout<<"present"<<endl;
	} else{
		cout<<"absent"<<endl;
	}
	return 0;
}