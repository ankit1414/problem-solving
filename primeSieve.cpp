#include<iostream>
using namespace std;
void primeSieve(int *arr,int n){
	arr[0] = arr[1]= -1;
	for(long long i=2; i<n; i++){

		if(arr[i] == 0){
			arr[i]=1;
			for(long long j=i*i; j<n; j += i){
				arr[j] = -1;
			}
		}
	}
}
int main() {
	int t;
	cin>>t;
	const int n = 1000002;
	int arr[n]={0};
	int precompute[n]={0};
	
	primeSieve(arr,n);
	//cout<<"here\n";
	for(int i=2; i<n; i++){
		if(arr[i] == 1){
			//cout<<i<<" ";
			precompute[i] = precompute[i-1]+1;
		}
		else
			precompute[i] = precompute[i-1];
	}
	while(t--){
		int s,e;
		cin>>s>>e;
		cout<<precompute[e]-precompute[s-1]<<endl;
	}

	return 0;
}