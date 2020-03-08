#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
	if(p1.second == p2.second)
		return p1.first<p2.first;
	return p1.second<p2.second;
}
int main() {
	int n;
	cin>>n;
	vector<pair<int,int>> v;
	v.reserve(n);
	for(int i=0; i<n; i++){
		int c,r;
		cin>>c>>r;
		v.push_back(make_pair(c,r));
	}
	sort(v.begin(),v.end(),compare);

	int count = 0;
	int i=1;
	auto prev = v[0];
	while(i<n){
		auto current = v[i];
		if(current.first-current.second<prev.first+prev.second){
			count++;
			if(prev.first+prev.second>current.first){
				prev = current;
			}
		}
		else{
			prev = current;
		}
		i++;
	}
	cout<<count<<endl;
	return 0;
}