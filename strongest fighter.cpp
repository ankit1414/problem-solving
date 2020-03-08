#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
int main() {

	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	int k;
	cin>>k;
	// this logic will not work

	//sample test case: 
	// 1 2 3 4 5 4 3 2 1 1
	// k = 3
	// helper arrray will be : 1 2 3 4 5 5 5 5 5 5 which is incorrect; 
	vector<int> helper;
	helper.reserve(n);
	helper.push_back(arr[0]);
	for(int i=1; i<n; i++){
		if(arr[i]>=helper[i-1]){
			helper.push_back(arr[i]);
		} else {
			helper.push_back(helper[i-1]);
		}
	}

	for(int i=k-1; i<helper.size(); i++){
		cout<<helper[i]<<" ";
	}
	return 0;
}
