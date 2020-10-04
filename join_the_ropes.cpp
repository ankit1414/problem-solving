/*
Q. given n ropes of different sizes, we are supposed to join the ropes together.
The cost of joining 2 ropes of different size 'a' & 'b' is =(a+b).
Find the minimum cost in order to join all ropes to make one.
*/

#include<iostream>
#include<queue>
using namespace std;

int cost_of_joining_all_ropes(int* a,int n){
    //priority_queue in stl is by default max heap so use this notation
    priority_queue<int,vector<int>,greater<int>>pq(a,a+n);
    int cost = 0;
    while(pq.size()>1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        cost+=first + second;
        pq.push(first+second);
    }
    return cost;
}

int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<cost_of_joining_all_ropes(a,n);
    return 0;
}