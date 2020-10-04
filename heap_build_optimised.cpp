#include<iostream>
#include<cmath>
using namespace std;

void downheapify(int* a,int size,int idx){
    if(size==0 || size==1){return;}
    int left_child_id = 2*idx +1;
    int right_child_id = 2*idx +2;
    if(left_child_id>=size){
        return;
    }
    if(right_child_id<size){
        int max_id = idx;
        if(a[left_child_id]>=a[right_child_id] && a[left_child_id]>a[idx]){
            max_id = left_child_id;
        }else if(a[right_child_id]>a[left_child_id] && a[right_child_id]>a[idx]){
            max_id = right_child_id;
        }
        if(max_id!=idx){
            swap(a[max_id],a[idx]);
            downheapify(a,size,max_id);
        }
    }else if(right_child_id==size){
        if(a[idx]<a[left_child_id]){
            swap(a[idx],a[left_child_id]);
            downheapify(a,size,left_child_id);
        }
    }

}

void buildHeap(int* a,int size){
    for(int i=size-1;i>=0;i--){
        downheapify(a,size,i);
    }
}

void display(int* a,int size){
    cout<<endl;
    if(size==0){
        cout<<"heap is empty"<<endl;
    }
    for(int i=0;i<size;i++){
        cout<<a[i]<<",";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"enter size of heap"<<endl;
    cin>>n;
    int size = n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    buildHeap(a,size);
    display(a,size);
    cout<<endl;
    return 0;
}