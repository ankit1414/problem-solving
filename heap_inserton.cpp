#include<iostream>
#include<cmath>
using namespace std;

void upheapify(int* a,int idx){
    if(idx==0){return;}
    int parent_id = floor((idx-1)/2);
    if(a[parent_id]<a[idx]){
        swap(a[parent_id],a[idx]);
        upheapify(a,parent_id);
    }
}

void insert_in_heap(int a[],int n,int key_id){
    if(key_id==0){
        return;
    }
    if(key_id>=n){
        cout<<"heap is full"<<endl;
        return;
    }
    upheapify(a,key_id);
}

void buildHeap(int a[],int n){
    for(int i=0;i<n;i++){
        insert_in_heap(a,n,i);
    }
}

int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    buildHeap(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<",";
    }
    cout<<endl;
    return 0;
}
