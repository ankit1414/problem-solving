#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
bool compare(pair<int,int> p1, pair<int,int> p2){
	if(p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second<p2.second;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int, int> > v(n);
		for(int i=0; i<n; i++){
			cin>>v[i].first>>v[i].second;
		}
		sort(v.begin(),v.end(),compare);
		int count=1;
		int fLast = 0;
		for(int i=1; i<n; i++){
			if(v[i].first>=v[fLast].second){
				count++;
				fLast = i;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}