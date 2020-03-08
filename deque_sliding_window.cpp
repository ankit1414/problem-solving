#include <iostream>
#include <deque>
using namespace std;
	
void printLargests(int *arr, int n, int k){

	deque<int> dq;
	int i;
	for(i=0; i<k; i++){
		while((!dq.empty()) && arr[i]>=arr[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	for( ; i<n; i++){
		cout<<arr[dq.front()]<<" ";
		while((!dq.empty()) && dq.front()<= i-k){ // this logic (i-k) makes it cover all windows
			dq.pop_front();
		}
		while((!dq.empty()) && arr[i]>=arr[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);

	}

	cout<<arr[dq.front()]<<endl;
	// cout<<arr[dq.back()]<<endl;
	

}

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	int k;
	cin>>k;
	printLargests(arr,n,k);



	return 0;
}