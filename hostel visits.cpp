#include <iostream>
#include <queue>
using namespace std;

int main(){

	int q,k;
	cin>>q>>k;
	priority_queue<long long int> pq;
	int counter = 1;
	while(q--){
		int type;
		cin>>type;
		if(type == 1){
			long long int x,y;
			cin>>x>>y;
			long long int dis = (x*x) + (y*y);
			if(counter<=k){
				pq.push(dis);
				counter++;
			} else {
				if(dis <= pq.top()){
					pq.pop();
					pq.push(dis);
				}
			}
		} else{
			cout<<pq.top()<<endl;
		}
	}
	return 0;
}