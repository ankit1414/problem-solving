#include<iostream>
using namespace std;
void doesExist(int *arr,int n, int i,int &count,int sum){
	
	//base case
	if(i==n){
		if(sum == 0){
			count++;
		}
		return ;
	}

	doesExist(arr,n,i+1,count,sum);
	sum += arr[i];
	doesExist(arr,n,i+1,count,sum);
}

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];
		int count=0;
		doesExist(arr,n,0,count,0);
		count >1 ? cout<<"Yes" : cout<<"No";
		//cout<<count<<endl;
		cout<<endl;
	}


	return 0;
}