#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main(){

	char ch;
	queue<char> q;
	unordered_map<char,int> mymap;
	cin>>ch;
	while(ch != '.'){

		q.push(ch);
		mymap[ch]++;

		while(!q.empty()){
			if(mymap[q.front()] == 1){
				cout<<q.front()<<endl;
				break;
			}
			else{
				q.pop();
			}
		}
		if(q.empty())	cout<<"-1"<<endl;

		cin>>ch;
	}
	return 0;
}